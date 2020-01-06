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
 * @file RamLatticeAssociation.h
 *
 * Defines the lattice of a Program of a relational algebra query
 *
 ***********************************************************************/

#pragma once

#include "RamNode.h"
#include "RamValue.h"
#include "RamTypes.h"
#include "RamLatticeBinaryFunction.h"
#include <string>

#include <iostream>

namespace souffle {

class RamLatticeAssociation: public RamNode {
private:
	/* Least upper bound */
	std::unique_ptr<RamLatticeBinaryFunction> lub = nullptr;

	/* Greatest lower bound */
	std::unique_ptr<RamLatticeBinaryFunction> glb = nullptr;

	/* lattice Bottom element */
	RamDomain bottom;

	/* lattice Top element */
	RamDomain top;

public:
	RamLatticeAssociation() :
			RamNode(RN_LatticeAssociation) {
	}

	/** Obtain child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();
	}

	/** Print */
	void print(std::ostream& out) const override {
		out << "LATTICE ASSOCIATION DEFINITION. " << std::endl;
		out << "lub: " << std::endl;
		lub->print(out);
		out << "glb: " << std::endl;
		glb->print(out);
	}

	/** set lub function */
	void setLUB(std::unique_ptr<RamLatticeBinaryFunction> l) {
		lub = move(l);
	}

	/** set glb function */
	void setGLB(std::unique_ptr<RamLatticeBinaryFunction> g) {
		glb = move(g);
	}

	const RamLatticeBinaryFunction& getLUB() {
		return *lub;
	}

	const RamLatticeBinaryFunction& getGLB() {
		return *glb;
	}

	void setBotTop(RamDomain b, RamDomain t) {
		assert(b != nullptr && t != nullptr);
		bottom = b;
		top = t;
		//std::cout << "bottom: "<<*b << " top:"<< *t << std::endl;
	}

	RamDomain getBot() const {
		return bottom;
	}

	RamDomain getTop() const {
		return top;
	}

	/** Add to leq function */
//	void addLeq(RamDomain* first, RamDomain* second, RamDomain* output) {
//		std::cout << "print LEQ:" << (first ? std::to_string(*first) : "_")
//				<< "," << (second ? std::to_string(*second) : "_") << ","
//				<< (output ? std::to_string(*output) : "_") << "\n";
//		leq.push_back( { first, second, output });
//	}
	/** Add to glb function */
//	void addGlb(RamDomain* first, RamDomain* second, RamDomain* output) {
//		std::cout << "print GLB:" << (first ? std::to_string(*first) : "_")
//				<< "," << (second ? std::to_string(*second) : "_") << ","
//				<< (output ? std::to_string(*output) : "_") << "\n";
//		glb.push_back( { first, second, output });
//	}
	/** should not apply any function here, do it in interpreter or compiler **/
	/*RamDomain applyLeq(RamDomain arg1, RamDomain arg2) {
	 // TODO: LEQ not finished, the output should be bool
	 for (auto& cur : leq) {
	 if ((cur.first == nullptr || *cur.first == arg1)
	 && (cur.second == nullptr || *cur.second == arg2)) {
	 return *cur.output;
	 }
	 }
	 std::cerr << "error: apply LEQ fail.\n";
	 throw(0);
	 }

	 RamDomain applyLub(RamDomain arg1, RamDomain arg2) {
	 for (auto& cur : lub) {
	 if (cur.first == nullptr) {
	 if (cur.second == nullptr)
	 return *cur.output;
	 else if (*cur.second == arg2) {
	 assert(cur.output == nullptr);
	 return arg1;
	 }
	 } else if (*cur.first == arg1) {
	 if (cur.second == nullptr) {
	 assert(cur.output == nullptr);
	 return arg2;
	 } else if (*cur.second == arg2) {
	 return *cur.output;
	 }
	 }

	 if ((cur.first==nullptr || *cur.first==arg1) && (cur.second==nullptr || *cur.second==arg2)) {
	 return *cur.output;
	 }
	 }
	 std::cerr << "error: apply LUB fail.\n";
	 throw(0);
	 }

	 RamDomain applyGlb(RamDomain arg1, RamDomain arg2) {
	 for (auto& cur : glb) {
	 if (cur.first == nullptr) {
	 if (cur.second == nullptr)
	 return *cur.output;
	 else if (*cur.second == arg2) {
	 assert(cur.output == nullptr);
	 return arg1;
	 }
	 } else if (*cur.first == arg1) {
	 if (cur.second == nullptr) {
	 assert(cur.output == nullptr);
	 return arg2;
	 } else if (*cur.second == arg2) {
	 return *cur.output;
	 }
	 }

	 if ((cur.first==nullptr || *cur.first==arg1) && (cur.second==nullptr || *cur.second==arg2)) {
	 return *cur.output;
	 }
	 }
	 std::cerr << "error: apply GLB fail.\n";
	 throw(0);
	 }*/

	/** Get relation */

	/** Create clone */
	RamLatticeAssociation* clone() const override {
		RamLatticeAssociation* res = new RamLatticeAssociation();
		//TODO
		return res;
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		//TODO
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamLatticeAssociation*>(&node));
		const auto& other = static_cast<const RamLatticeAssociation&>(node);
		return lub == other.lub && glb == other.glb;
	}
};

}  // end of namespace souffle
