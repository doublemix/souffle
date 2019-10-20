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

namespace souffle {

/**
 * Subclass of AstArgument that represents an Lattice Binary function/operation
 */
class AstLatticeBinaryFunction : public AstNode {
public:
	/** The type utilized to model a field */
	struct PairMap {
		AstArgument* first;		// < the first of the pair
		AstArgument* second;	// < the second of the pair
		AstArgument* output;	// < the output of the pair

//		std::string first;        // < the first of the pair
//		std::string second;  		// < the second of the pair
//		std::string output;		// < the output of the pair

		bool operator==(const PairMap& other) const {
			return this == &other || (first == other.first && second == other.second && output == other.output);
		}
	};

	AstLatticeBinaryFunction() = default;

	AstLatticeBinaryFunction(std::string name) : name(std::move(name)) {}

	~AstLatticeBinaryFunction() override = default;

	/** get name */
	const std::string& getName() const {
		return name;
	}

	/** set name */
	void setName(const std::string& n) {
		name = n;
	}

	/** get output */
	const std::string& getOutput() const {
		return func_output;
	}

	/** set output **/
	void setOutput(const std::string& output) {
		func_output = output;
	}

	/** get number of arguments */
	size_t getArgCount() const {
		return args.size();
	}

	/** get arguments */
	std::vector<std::string> getArguments() const {
		return args;
	}

	/** add argument to argument list */
	void addArg(const std::string& arg) {
		args.push_back(arg);
	}

	/** add argument to argument list */
	void addPairMap(AstArgument* first, AstArgument* second, AstArgument* output) {
		pairmaps.push_back({first, second, output});
	}

	const std::vector<PairMap>& getPairMap() const {
		return pairmaps;
	}

	/** print user-defined functor */
	void print(std::ostream& os) const override {
		os << "LatticeBinaryFunction: @" << name << " (";
		os << args[0];
		for (size_t i=1; i<args.size(); i++) {
			os << "," << args[i];
		}
		os << "):";
		os << func_output;
		os << "{\n";
		for (auto& pm : pairmaps) {
			os << "(" << *pm.first << "," << *pm.second << ")=>" << *pm.output;
			os << "\n";
		}
		os << "}";
	}

	std::vector<const AstNode*> getChildNodes() const override {
			auto res = std::vector<const AstNode*>();
			// TODO
			return res;
		}

	AstLatticeBinaryFunction* clone() const override {
		// TODO
		AstLatticeBinaryFunction* res = new AstLatticeBinaryFunction(name);
		res->setSrcLoc(getSrcLoc());
		return res;
	}

	/** Mutates this node */
	void apply(const AstNodeMapper& map) override {
		// TODO
	}

protected:
	/** name of lattice binary function */
	std::string name;

	/** arguments of lattice binary function */
	std::vector<std::string> args;

	/** output of lattice binary function **/
	std::string func_output;

	/** lattice pair map **/
	std::vector<PairMap> pairmaps;

	/** Implements the node comparison for this node type */
	bool equal(const AstNode& node) const override {
		assert(nullptr != dynamic_cast<const AstLatticeBinaryFunction*>(&node));
		const auto& other = static_cast<const AstLatticeBinaryFunction&>(node);
		return name==other.getName() && pairmaps==other.pairmaps;
	}
};

}   // end of namespace souffle
