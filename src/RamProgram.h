/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2017, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file RamProgram.h
 *
 * Defines a Program of a relational algebra query
 *
 ***********************************************************************/

#pragma once

#include "RamStatement.h"

namespace souffle {

class RamProgram: public RamNode {
private:
	/** Relations of RAM program */
	std::map<std::string, std::unique_ptr<RamRelation>> relations;

	/** Main program */
	std::unique_ptr<RamStatement> main;

	/** Subroutines for querying computed relations */
	std::map<std::string, std::unique_ptr<RamStatement>> subroutines;

	/** Lattice association **/
	std::unique_ptr<RamLatticeAssociation> lattice;

	/** all lattice unary functions **/
	std::map<std::string, std::shared_ptr<RamLatticeUnaryFunction>> LUFs;

	/** all lattice binary functions **/
	std::map<std::string, std::shared_ptr<RamLatticeBinaryFunction>> LBFs;

public:
	RamProgram() :
			RamNode(RN_Program) {
	}
	RamProgram(std::unique_ptr<RamStatement> main) :
			RamNode(RN_Program), main(std::move(main)) {
	}

	/** Obtain child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		std::vector<const RamNode*> children;

		// add relations
		for (auto& r : relations) {
			children.push_back(r.second.get());
		}

		// add main program
		children.push_back(main.get());

		// add subroutines
		for (auto& s : subroutines) {
			children.push_back(s.second.get());
		}
		return children;
	}

	/** Print */
	void print(std::ostream& out) const override {
		out << "DECLARATION " << std::endl;
		for (const auto& rel : relations) {
			rel.second->print(out);
		}
		if (lattice != nullptr) {
			lattice->print(out);
		}
		for (const auto& luf : LUFs) {
			out << "function " << luf.first << ":" << std::endl;
			luf.second->print(out);
		}
		for (const auto& lbf : LBFs) {
			out << "function " << lbf.first << ":" << std::endl;
			lbf.second->print(out);
		}
		out << "END DECLARATION " << std::endl;
		out << "PROGRAM" << std::endl;
		out << *main;
		out << "\nEND PROGRAM" << std::endl;
		for (const auto& subroutine : subroutines) {
			out << std::endl << "SUBROUTINE " << subroutine.first << std::endl;
			out << *subroutine.second;
			out << "\nEND SUBROUTINE" << std::endl;
		}
	}

	/** Set main program */
	void setMain(std::unique_ptr<RamStatement> stmt) {
		main = std::move(stmt);
	}

	/** Get main program */
	RamStatement* getMain() const {
		assert(main);
		return main.get();
	}

	/** Add relation */
	void addRelation(std::unique_ptr<RamRelation> rel) {
		relations.insert(std::make_pair(rel->getName(), std::move(rel)));
	}

	/** Get relation */
	const RamRelation* getRelation(const std::string& name) const {
		auto it = relations.find(name);
		if (it != relations.end()) {
			return it->second.get();
		} else {
			return nullptr;
		}
	}

	/** Add subroutine */
	void addSubroutine(std::string name,
			std::unique_ptr<RamStatement> subroutine) {
		subroutines.insert(std::make_pair(name, std::move(subroutine)));
	}

	/** Get subroutines */
	const std::map<std::string, RamStatement*> getSubroutines() const {
		std::map<std::string, RamStatement*> subroutineRefs;
		for (auto& s : subroutines) {
			subroutineRefs.insert( { s.first, s.second.get() });
		}
		return subroutineRefs;
	}

	/** Get subroutine */
	const RamStatement& getSubroutine(const std::string& name) const {
		return *subroutines.at(name);
	}

	/** Set lattice */
	void setLattice(std::unique_ptr<RamLatticeAssociation> lat) {
		lattice = std::move(lat);
	}

	/** Get lattice */
	RamLatticeAssociation* getLattice() const {
		assert(lattice);
		return lattice.get();
	}

	/** add lattice binary function **/
	void addLUF(std::string name,
			std::shared_ptr<RamLatticeUnaryFunction> luf) {
		assert(LUFs.find(name) == LUFs.end());
		LUFs.insert( { name, luf });
	}

	std::map<std::string, std::shared_ptr<souffle::RamLatticeUnaryFunction>> getLUFs () const {
		return LUFs;
	}

	/** get a pointer to a lattice unary function from its name **/
	std::shared_ptr<RamLatticeUnaryFunction> getLUF(std::string name) {
		auto it = LUFs.find(name);
		return it == LUFs.end() ? nullptr : it->second;
	}

	/** add lattice binary function **/
	void addLBF(std::string name,
			std::shared_ptr<RamLatticeBinaryFunction> lbf) {
		assert(LBFs.find(name) == LBFs.end());
		LBFs.insert( { name, lbf });
	}

	std::map<std::string, std::shared_ptr<souffle::RamLatticeBinaryFunction>> getLBFs () const {
		return LBFs;
	}

	/** get a pointer to a lattice binary function from its name **/
	std::shared_ptr<RamLatticeBinaryFunction> getLBF(std::string name) {
		auto it = LBFs.find(name);
//		if (it==LBFs.end()) {
//			return std::shared_ptr<RamLatticeBinaryFunction>(nullptr);
//		} else {
//			return it->second;
//		}
		return it == LBFs.end() ? nullptr : it->second;
	}

	/** Create clone */
	RamProgram* clone() const override {
		RamProgram* res = new RamProgram(
				std::unique_ptr<RamStatement>(main->clone()));
		for (auto& cur : subroutines) {
			res->addSubroutine(cur.first,
					std::unique_ptr<RamStatement>(cur.second->clone()));
		}
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		main = map(std::move(main));
		for (auto& cur : subroutines) {
			subroutines[cur.first] = map(std::move(cur.second));
		}
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamProgram*>(&node));
		const auto& other = static_cast<const RamProgram&>(node);
		bool areSubroutinesEqual = true;
		for (auto& cur : subroutines) {
			if (other.subroutines.count(cur.first) == 0) {
				areSubroutinesEqual = false;
				break;
			} else {
				if (other.getSubroutine(cur.first)
						!= getSubroutine(cur.first)) {
					areSubroutinesEqual = false;
					break;
				}
			}
		}
		return getMain() == other.getMain() && areSubroutinesEqual;
	}
};

}  // end of namespace souffle
