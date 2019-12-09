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
 * @file RamLatticeBinaryFunction.h
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

class RamLatticeBinaryFunction: public RamNode {
private:
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

	/* vector of cases for lattice binary function */
	std::vector<LatCase> cases;

public:
	RamLatticeBinaryFunction():
		RamNode(RN_LatticeBinaryFunction) {
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

	const std::vector<LatCase>& getCase() {
		return cases;
	}

	/** Create clone */
	RamLatticeBinaryFunction* clone() const override {
		RamLatticeBinaryFunction* res = new RamLatticeBinaryFunction();
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
		assert(nullptr != dynamic_cast<const RamLatticeBinaryFunction*>(&node));
		const auto& other = static_cast<const RamLatticeBinaryFunction&>(node);
		return cases == other.cases;
	}
};

}  // end of namespace souffle
