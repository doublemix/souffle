/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2017, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/** author: Gong, Qing **/

/************************************************************************
 *
 * @file RamLatticeFunction.h
 *
 * Defines the lattice binary function for RAM
 *
 ***********************************************************************/

#pragma once

#include "RamNode.h"
#include "RamValue.h"
#include "RamTypes.h"
#include "RamCondition.h"
#include <string>

#include <iostream>

namespace souffle {

class RamLatticeFunction: public RamNode {
	std::string name;
public:
	RamLatticeFunction(RamNodeType type, const std::string& name): RamNode(type), name(name) {}

	std::string getName() const { return name; }
};

/**
 * Lattice Unary Function declaration
 */
class RamLatticeUnaryFunction: public RamLatticeFunction {
public:
	/** The type utilized to model a field */
	// Example: "case (Bot)=> x=2 ? y*2 : x"
	struct LatCase {
		std::unique_ptr<RamConstraint> constraint = nullptr;
		std::unique_ptr<RamValue> output = nullptr;
		LatCase(std::unique_ptr<RamConstraint> m, std::unique_ptr<RamValue> o) :
			constraint(move(m)), output(move(o)) {
		}
		bool operator==(const LatCase& other) const {
			return this == &other
					|| (*constraint == *other.constraint && *output == *other.output);
		}
	};

	RamLatticeUnaryFunction(const std::string& name):
		RamLatticeFunction(RN_LatticeUnaryFunction, name) {
	}

	/** Obtain child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();
	}

	/** Print */
	void print(std::ostream& out) const override {
		//#define PrintLatCase(x) (((x)!=nullptr) ? std::to_string(*(x)) : "_")
		out << "LATTICE UNARY FUNCTION " << std::endl;
		out << "size: " << Unarycases.size() << std::endl;
		for (auto& cur : Unarycases) {
			out << "match:";
			if (cur.constraint!=nullptr)
				cur.constraint->print(out);
			else
				out << "True";
			out << ", output:";
			cur.output->print(out);
			out << std::endl;
		}
	}

	/** Add to cases of function */
	void addCase(std::unique_ptr<RamConstraint> match, std::unique_ptr<RamValue> output) {
		Unarycases.emplace_back(move(match), move(output));
	}

	const std::vector<LatCase>& getLatCase() const {
		return Unarycases;
	}

	/** Create clone */
	RamLatticeUnaryFunction* clone() const override {
		RamLatticeUnaryFunction* res = new RamLatticeUnaryFunction(getName());
		for (auto& unarycase : Unarycases) {
			res->Unarycases.emplace_back(
				std::unique_ptr<RamConstraint>(unarycase.constraint == nullptr ? nullptr : unarycase.constraint->clone()),
				std::unique_ptr<RamValue>(unarycase.output->clone()));
		}
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		//TODO
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamLatticeUnaryFunction*>(&node));
		const auto& other = static_cast<const RamLatticeUnaryFunction&>(node);
		return Unarycases == other.Unarycases;
	}

private:
	/* vector of cases for lattice Unary function */
	std::vector<LatCase> Unarycases;

};

/**
 * Lattince Binary Function declaration
 */
class RamLatticeBinaryFunction: public RamLatticeFunction {
public:
	/** The type utilized to model a field */
	// Example: "case (Bot,x)=>x>2 ? y*2 : x"
	struct LatCase {
		std::unique_ptr<RamCondition> match = nullptr;
		std::unique_ptr<RamValue> output = nullptr;
		LatCase(std::unique_ptr<RamCondition> m, std::unique_ptr<RamValue> o) :
				match(move(m)), output(move(o)) {
		}
		bool operator==(const LatCase& other) const {
			return this == &other
					|| (*match == *other.match && *output == *other.output);
		}
	};

	RamLatticeBinaryFunction(const std::string& name):
		RamLatticeFunction(RN_LatticeBinaryFunction, name) {
	}

	/** Obtain child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();
	}

	/** Print */
	void print(std::ostream& out) const override {
		//#define PrintLatCase(x) (((x)!=nullptr) ? std::to_string(*(x)) : "_")
		out << "LATTICE BINARY FUNCTION " << std::endl;
		out << "size: " << cases.size() << std::endl;
		for (auto& cur : cases) {
			out << "match:";
			if (cur.match!=nullptr)
				cur.match->print(out);
			else
				out << "True";
			out << ", output:";
			cur.output->print(out);
			out << std::endl;
		}
	}

	/** Add to cases of function */
	void addCase(std::unique_ptr<RamCondition> match, std::unique_ptr<RamValue> output) {
		cases.emplace_back(move(match), move(output));
	}

	const std::vector<LatCase>& getLatCase() const {
		return cases;
	}

	/** Create clone */
	RamLatticeBinaryFunction* clone() const override {
		RamLatticeBinaryFunction* res = new RamLatticeBinaryFunction(getName());
		for (auto& bincase : cases) {
			res->cases.emplace_back(
				std::unique_ptr<RamCondition>(bincase.match == nullptr ? nullptr : bincase.match->clone()),
				std::unique_ptr<RamValue>(bincase.output->clone()));
		}
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		//TODO
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamLatticeBinaryFunction*>(&node));
		const auto& other = static_cast<const RamLatticeBinaryFunction&>(node);
		return cases == other.cases;
	}

private:
	/* vector of cases for lattice binary function */
	std::vector<LatCase> cases;
};

}  // end of namespace souffle
