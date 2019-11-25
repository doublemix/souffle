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
#include <string>

#include <iostream>

namespace souffle {

class RamLatticeAssociation: public RamNode {
private:
	/** The type utilized to model a field */
	// TODO: should not be RamDomain, consider "case (Bot,x)=>x", x is not in symbol table
	struct LatCase {
//		RamDomain* first = nullptr;     // < the first input of the binary function
//		RamDomain* second = nullptr;  	// < the second input of the binary function
//		RamDomain* output = nullptr;	// < the output of the binary function
//
//		LatCase(RamDomain* f, RamDomain* s, RamDomain* o): first(f), second(s), output(o) {}

		std::unique_ptr<RamValue> first = nullptr;
		std::unique_ptr<RamValue> second = nullptr;
		std::unique_ptr<RamValue> output = nullptr;
		LatCase(std::unique_ptr<RamValue> f, std::unique_ptr<RamValue> s, std::unique_ptr<RamValue> o) :
				first(move(f)), second(move(s)), output(move(o)) {
		}
		bool operator==(const LatCase& other) const {
			return this == &other
					|| (*first == *other.first && *second == *other.second
							&& *output == *other.output);
		}

	};

	/** top element for the lattice **/
	RamDomain* top;

	/** bottom element for the lattice **/
	RamDomain* bottom;

	/** LEQ relation of the lattice */
	std::vector<LatCase> leq;

	/** Least upper bound of the lattice */
	std::vector<LatCase> lub;

	/** Greatest lower bound of the lattice */
	std::vector<LatCase> glb;

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
#define PrintLatCase(x) (((x)!=nullptr) ? std::to_string(*(x)) : "_")
		out << "LATTICE ASSOCIATION DEFINITION. " << std::endl;
		out << "leq, size: " << leq.size() << std::endl;
		for (auto& cur : leq) {
			out << "first:";
			cur.first->print(out);
			out << ", second:";
			cur.second->print(out);
			out << ", output:";
			cur.output->print(out);
			out << std::endl;
//			out << "first:" << PrintLatCase(cur.first) << ",second:" << PrintLatCase(cur.second)
//																<< ",output:" << PrintLatCase(cur.output) << std::endl;
		}
		out << "lub size: " << lub.size() << std::endl;
		for (auto& cur : lub) {
			out << "first:";
			cur.first->print(out);
			out << ", second:";
			cur.second->print(out);
			out << ", output:";
			cur.output->print(out);
			out << std::endl;
//			out << "first:" << PrintLatCase(cur.first) << ",second:" << PrintLatCase(cur.second)
//																<< ",output:" << PrintLatCase(cur.output) << std::endl;
		}
		out << "glb size: " << glb.size() << std::endl;
		for (auto& cur : glb) {
			out << "first:";
			cur.first->print(out);
			out << ", second:";
			cur.second->print(out);
			out << ", output:";
			cur.output->print(out);
			out << std::endl;
//			out << "first:" << PrintLatCase(cur.first) << ",second:"
//					<< PrintLatCase(cur.second) << ",output:"
//					<< PrintLatCase(cur.output) << std::endl;
		}
	}

	void addBotTop(RamDomain *b, RamDomain *t) {
		assert(b != nullptr && t != nullptr);
		bottom = b;
		top = t;
		//std::cout << "bottom: "<<*b << " top:"<< *t << std::endl;
	}

	RamDomain getBot() const {
		return *bottom;
	}

	RamDomain getTop() const {
		return *top;
	}

	/** Add to leq function */
	void addLeq(std::unique_ptr<RamValue> first, std::unique_ptr<RamValue> second, std::unique_ptr<RamValue> output) {
		leq.emplace_back(move(first), move(second), move(output));
	}

	/** Add to leq function */
//	void addLeq(RamDomain* first, RamDomain* second, RamDomain* output) {
//		std::cout << "print LEQ:" << (first ? std::to_string(*first) : "_")
//				<< "," << (second ? std::to_string(*second) : "_") << ","
//				<< (output ? std::to_string(*output) : "_") << "\n";
//		leq.push_back( { first, second, output });
//	}
	/** Add to lub function */
	void addLub(std::unique_ptr<RamValue> first, std::unique_ptr<RamValue> second, std::unique_ptr<RamValue> output) {
		lub.emplace_back(move(first), move(second), move(output));
	}

	/** Add to lub function */
//	void addLub(RamDomain* first, RamDomain* second, RamDomain* output) {
//		std::cout << "print LUB:" << (first ? std::to_string(*first) : "_")
//				<< "," << (second ? std::to_string(*second) : "_") << ","
//				<< (output ? std::to_string(*output) : "_") << "\n";
//
//		lub.push_back( { first, second, output });
//	}
	/** Add to glb function */
	void addGlb(std::unique_ptr<RamValue> first, std::unique_ptr<RamValue> second, std::unique_ptr<RamValue> output) {
		glb.emplace_back(move(first), move(second), move(output));
	}

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
		return leq == other.leq && lub == other.lub && glb == other.glb;
	}
};

}  // end of namespace souffle
