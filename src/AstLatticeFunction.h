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

/*
 * Represents a lattice function
 */
class AstLatticeFunction: public AstNode {
public:
	AstLatticeFunction() = default;
	AstLatticeFunction(std::string name) :
			name(std::move(name)) {
	}

	/** get name */
	const std::string& getName() const {
		return name;
	}

	/** set name */
	void setName(const std::string& n) {
		name = n;
	}
protected:
	/** name of lattice binary function */
	std::string name;
};

/**
 * represents a lattice unary function
 */
class AstLatticeUnaryFunction: public AstLatticeFunction {
public:
	struct UnaryMap {
		AstArgument* first;
		AstArgument* output;

		bool operator==(const UnaryMap& other) const {
			return this == &other
					|| (first == other.first && output == other.output);
		}
	};

	AstLatticeUnaryFunction() = default;
	AstLatticeUnaryFunction(std::string name) :
			AstLatticeFunction(name) {
	}

	~AstLatticeUnaryFunction() override = default;

	/** get name */
//	const std::string& getName() const {
//		return name;
//	}
//
//	/** set name */
//	void setName(const std::string& n) {
//		name = n;
//	}
	/** get output */
	const std::string& getOutput() const {
		return func_output;
	}

	/** set output **/
	void setOutput(const std::string& output) {
		func_output = output;
	}

	/** get arguments */
	const std::string& getArgument() const {
		assert(arg!="");
		return arg;
	}

	/** set argument to argument list */
	void setArg(const std::string& a) {
		arg = a;
	}

	/** add argument to argument list */
	void addUnaryMap(AstArgument* first, AstArgument* output) {
		unarymap.push_back( { first, output });
	}

	const std::vector<UnaryMap>& getUnaryMap() const {
		return unarymap;
	}

	/** print user-defined functor */
	void print(std::ostream& os) const override {
		os << "LatticeUnaryFunction: &" << name << " (";
		os << arg;
		os << "):";
		os << func_output;
		os << "{\n";
		for (auto& um : unarymap) {
			os << "(";
			um.first->print(os);
			os << ")=>";
			um.output->print(os);
			os << "\n";
		}
		os << "}";
	}

	std::vector<const AstNode*> getChildNodes() const override {
		auto res = std::vector<const AstNode*>();
		// TODO
		return res;
	}

	AstLatticeUnaryFunction* clone() const override {
		// TODO
		AstLatticeUnaryFunction* res = new AstLatticeUnaryFunction(name);
		res->setSrcLoc(getSrcLoc());
		return res;
	}

	/** Mutates this node */
	void apply(const AstNodeMapper& map) override {
		// TODO
	}

protected:
	/** name of lattice binary function */
//	std::string name;
	/** arguments of lattice binary function */
	std::string arg;

	/** output of lattice binary function **/
	std::string func_output;

	/** lattice unary map **/
	std::vector<UnaryMap> unarymap;

	/** Implements the node comparison for this node type */
	bool equal(const AstNode& node) const override {
		assert(nullptr != dynamic_cast<const AstLatticeUnaryFunction*>(&node));
		const auto& other = static_cast<const AstLatticeUnaryFunction&>(node);
		return name == other.getName() && unarymap == other.unarymap;
	}
};

/**
 * Subclass of AstArgument that represents a Lattice Binary function
 */
class AstLatticeBinaryFunction: public AstLatticeFunction {
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
			return this == &other
					|| (first == other.first && second == other.second
							&& output == other.output);
		}
	};

	AstLatticeBinaryFunction() = default;

	AstLatticeBinaryFunction(std::string name) :
			AstLatticeFunction(name) {
	}

	~AstLatticeBinaryFunction() override = default;

	/** get name */
//	const std::string& getName() const {
//		return name;
//	}
//
//	/** set name */
//	void setName(const std::string& n) {
//		name = n;
//	}
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
	const std::vector<std::string>& getArguments() const {
		assert(args.size()==2);
		return args;
	}

	/** add argument to argument list */
	void addArg(const std::string& arg) {
		args.push_back(arg);
	}

	/** add argument to argument list */
	void addPairMap(AstArgument* first, AstArgument* second,
			AstArgument* output) {
		pairmaps.push_back( { first, second, output });
	}

	const std::vector<PairMap>& getPairMap() const {
		return pairmaps;
	}

	/** print user-defined functor */
	void print(std::ostream& os) const override {
		os << "LatticeBinaryFunction: &" << name << " (";
		os << args[0];
		for (size_t i = 1; i < args.size(); i++) {
			os << "," << args[i];
		}
		os << "):";
		os << func_output;
		os << "{\n";
		for (auto& pm : pairmaps) {
			os << "(";
			pm.first->print(os);
			os << ",";
			pm.second->print(os);
			os << ")=>";
			pm.output->print(os);
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
//	std::string name;
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
		return name == other.getName() && pairmaps == other.pairmaps;
	}
};

}   // end of namespace souffle
