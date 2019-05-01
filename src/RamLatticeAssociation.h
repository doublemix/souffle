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
#include "RamTypes.h"
#include <string>

namespace souffle {

class RamLatticeAssociation : public RamNode {
private:
	/** The type utilized to model a field */
	// TODO: should not be RamDomain, consider "case (Bot,x)=>x", x is not in symbol table
	struct LatCase {
		RamDomain* first = nullptr;     // < the first input of the binary function
		RamDomain* second = nullptr;  	// < the second input of the binary function
		RamDomain* output = nullptr;	// < the output of the binary function

		LatCase(RamDomain* f, RamDomain* s, RamDomain* o): first(f), second(s), output(o) {}
		bool operator==(const LatCase& other) const {
			return this == &other || (*first == *other.first && *second == *other.second && *output == *other.output);
		}
	};

	/** LEQ relation of the lattice */
	std::vector<LatCase> leq;

	/** Least upper bound of the lattice */
	std::vector<LatCase> lub;

	/** Greatest lower bound of the lattice */
	std::vector<LatCase> glb;

public:
	RamLatticeAssociation() : RamNode(RN_LatticeAssociation) {}

	/** Obtain child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*> ();
	}

	/** Print */
	void print(std::ostream& out) const override {
#define PrintLatCase(x) (((x)!=nullptr) ? std::to_string(*(x)) : "_")
		out << "LATTICE ASSOCIATION DEFINITION. " << std::endl;
		out << "leq, size: " << leq.size() << std::endl;
		for (auto& cur : leq) {
			out << "first:" << PrintLatCase(cur.first) << ",second:" << PrintLatCase(cur.second)
				<< ",output:" << PrintLatCase(cur.output) << std::endl;
		}
		out << "lub size: " << lub.size() << std::endl;
		for (auto& cur : lub) {
			out << "first:" << PrintLatCase(cur.first) << ",second:" << PrintLatCase(cur.second)
				<< ",output:" << PrintLatCase(cur.output) << std::endl;
		}
		out << "glb size: " << glb.size() << std::endl;
		for (auto& cur : glb) {
			out << "first:" << PrintLatCase(cur.first) << ",second:" << PrintLatCase(cur.second)
				<< ",output:" << PrintLatCase(cur.output) << std::endl;
		}
	}

	/** Add to leq function */
	void addLeq(RamDomain* first, RamDomain* second, RamDomain* output) {
		leq.push_back({first, second, output});
	}

	/** Add to lub function */
	void addLub(RamDomain* first, RamDomain* second, RamDomain* output) {
		lub.push_back({first, second, output});
	}

	/** Add to glb function */
	void addGlb(RamDomain* first, RamDomain* second, RamDomain* output) {
		glb.push_back({first, second, output});
	}

	/** Get relation */


	/** Create clone */
	RamLatticeAssociation* clone() const override {
		RamLatticeAssociation* res = new RamLatticeAssociation();
		for (auto& cur : leq) {
			res->addLeq(cur.first, cur.second, cur.output);
		}
		for (auto& cur : lub) {
			res->addLub(cur.first, cur.second, cur.output);
		}
		for (auto& cur : glb) {
			res->addGlb(cur.first, cur.second, cur.output);
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
		assert(nullptr != dynamic_cast<const RamLatticeAssociation*>(&node));
		const auto& other = static_cast<const RamLatticeAssociation&>(node);
		return leq == other.leq && lub == other.lub && glb == other.glb;
	}
};

}  // end of namespace souffle
