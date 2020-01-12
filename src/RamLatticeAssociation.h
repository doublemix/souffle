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

#include <vector>

namespace souffle {

class RamLatticeAssociation: public RamNode {
private:
	/* Least upper bound */
	std::shared_ptr<RamLatticeBinaryFunction> lub = nullptr;

	/* Greatest lower bound */
	std::shared_ptr<RamLatticeBinaryFunction> glb = nullptr;

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
	void setLUB(std::shared_ptr<RamLatticeBinaryFunction> l) {
		lub = l;
	}

	/** set glb function */
	void setGLB(std::shared_ptr<RamLatticeBinaryFunction> g) {
		glb = g;
	}

	const RamLatticeBinaryFunction& getLUB() {
		return *lub;
	}

	const RamLatticeBinaryFunction& getGLB() {
		return *glb;
	}

	void setBotTop(RamDomain b, RamDomain t) {
		assert(b != 0 && t != 0);
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

	/* add a new lattice binary function other than GLB, LUB, then return
	 * its index in the vector */
//	size_t addOtherLBF(std::unique_ptr<RamLatticeBinaryFunction> lbf) {
//		size_t ind = otherLatticeBinaryFunctions.size();
//		otherLatticeBinaryFunctions.push_back(std::move(lbf));
//		return ind;
//	}

	/* return the lattice binary function based on index */
//	const RamLatticeBinaryFunction& getOtherLBF(size_t ind) {
//		return *(otherLatticeBinaryFunctions[ind]);
//	}

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
