/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2019, The Souffle Developers. All rights reserved.
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/** author: Gong, Qing **/

/************************************************************************
 *
 * @file AstLatticeBinaryFunction.h
 *
 * Defines lattice binary functions: leq, lub, glb
 *
 ***********************************************************************/

#pragma once

#include "AstNode.h"
#include "AstArgument.h"
#include "AstTypes.h"
#include "FunctorOps.h"
#include "SymbolTable.h"
#include "Util.h"
#include <cassert>
#include <cstddef>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include "AstLatticeFunction.h"

namespace souffle {

class AstLatticeAssociation : public AstNode {
public:
	AstLatticeAssociation() = default;

	AstLatticeAssociation(std::string name) : name(std::move(name)) {}

	~AstLatticeAssociation() override = default;

	/** get name */
	const std::string& getName() const {
		return name;
	}

	/** set name */
	void setName(const std::string& n) {
		name = n;
	}

	void setALL(const std::string& B, const std::string& T, const std::string& LUB, const std::string& GLB) {
		assert(B!="" && T!="" && LUB!="" && GLB!="");
		bottom = B;
		top = T;
		lub = LUB;
		glb = GLB;
	}

	const std::string& getTop() const {
		return top;
	}

	const std::string& getBottom() const {
		return bottom;
	}

	const std::string& getLub() const {
		return lub;
	}

	const std::string& getGlb() const {
		return glb;
	}

	AstLatticeAssociation* clone() const override {
		auto res = new AstLatticeAssociation(name);
		res->setALL(top, bottom, lub, glb);
		return res;
	}

	/** Mutates this node */
	void apply(const AstNodeMapper& /*mapper*/) override {
		// TODO
	}

	std::vector<const AstNode*> getChildNodes() const override {
		auto res = std::vector<const AstNode*>();
		/*res.push_back(top.get());
		res.push_back(bottom.get());
		res.push_back(leq.get());
		res.push_back(lub.get());
		res.push_back(glb.get());*/
		return res;
	}

	void print(std::ostream& os) const override {
		os << "Lattice Association: " << name << "<> = (\n";
		os << "Bottom element: " << bottom << "\n";
		os << "Top element: " << top << "\n";
		os << "lub function name: " << lub << "\n";
		os << "glb function name: " << glb << "\n";
		os << ")";
	}


protected:
	/** name of lattice binary function */
	std::string name;

	/** top element for the lattice **/
	std::string top;

	/** bottom element for the lattice **/
	std::string bottom;

	/** least upper bound **/
	std::string lub;

	/** greatest lower bound **/
	std::string glb;

	/** Implements the node comparison for this node type */
	bool equal(const AstNode& node) const override {
		assert(nullptr != dynamic_cast<const AstLatticeAssociation*>(&node));
		const auto& other = static_cast<const AstLatticeAssociation&>(node);
		return name==other.getName() && lub==(other.lub) && glb==(other.glb) && top==(other.top) && bottom==(other.bottom);
	}
};
}


