/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2015, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file InterpreterRelation.h
 *
 * Defines Interpreter Relations
 *
 ***********************************************************************/

#pragma once

#include "InterpreterIndex.h"
#include "ParallelUtils.h"
#include "RamTypes.h"

#include "RamLatticeAssociation.h"

#include <deque>
#include <map>
#include <memory>
#include <vector>

namespace souffle {

/**
 * Interpreter Relation
 */
class InterpreterRelation {
public:
	InterpreterRelation(size_t relArity) :
			arity(relArity), num_tuples(0), totalIndex(nullptr) {
	}

	InterpreterRelation(const InterpreterRelation& other) = delete;

	virtual ~InterpreterRelation() = default;

	/** Get arity of relation */
	size_t getArity() const {
		return arity;
	}

	/** Check whether relation is empty */
	bool empty() const {
		return num_tuples == 0;
	}

	/** Gets the number of contained tuples */
	size_t size() const {
		return num_tuples;
	}

	const InterpreterIndex* getTotalIndex() const {
		if (!totalIndex) {
			totalIndex = getIndex(getTotalIndexKey());
		}
		assert(totalIndex != nullptr);
		return totalIndex;
	}

	/** Insert tuple */
	virtual void insert(const RamDomain* tuple) {
		// check for null-arity
		if (arity == 0) {
			// set number of tuples to one -- that's it
			num_tuples = 1;
			return;
		}

		assert(tuple);

		// make existence check
		if (exists(tuple)) {
			return;
		}

		int blockIndex = num_tuples / (BLOCK_SIZE / arity);
		int tupleIndex = (num_tuples % (BLOCK_SIZE / arity)) * arity;

		if (tupleIndex == 0) {
			blockList.push_back(std::make_unique<RamDomain[]>(BLOCK_SIZE));
		}

		RamDomain* newTuple = &blockList[blockIndex][tupleIndex];
		for (size_t i = 0; i < arity; ++i) {
			newTuple[i] = tuple[i];
		}

		// update all indexes with new tuple
		for (const auto& cur : indices) {
			cur.second->insert(newTuple);
		}

		// increment relation size
		num_tuples++;
	}

	/** Merge another relation into this relation */
	void insert(const InterpreterRelation& other) {
		assert(getArity() == other.getArity());
		for (const auto& cur : other) {
			insert(cur);
		}
	}

	/** Find the biggest lattice element for each cell, and insert
	 *  to both itself and the other relation **/
	/*latnorm is visided after merge, eg:
	 MERGE R WITH @new_R;
	 LATNORM R AND @new_R;
	 so we traverse R and find the biggest lattice*/
// Notice: Only last element is fixed to lattice element!
//	void latnorm(InterpreterRelation& other, RamLatticeAssociation* latAssoc) {
//		assert(arity == other.getArity());
//
//		InterpreterContext ctxt_temp;
//		const RamLatticeBinaryFunction& lub_func = latAssoc->getLUB();
//
//		RamDomain high[arity];
//		if (!totalIndex) {
//			totalIndex = getIndex(getTotalIndexKey());
//		}
//		auto it = totalIndex->begin();
//		auto itend = totalIndex->end();
//
//		// todo: move to interpreter.cpp, only need send iterator it and itend to interpreter.
//		while (it != itend) {
//			const RamDomain* data = *(it);
//			for (size_t i = 0; i < arity - 1; i++) {
//				high[i] = data[i];
//			}
//			high[arity - 1] = MAX_RAM_DOMAIN;
//			// get iterator range
//			auto range_end = totalIndex->UpperBound(high);
////			RamDomain biggestLat = latAssoc->getBot();
//			RamDomain biggestLat = (*it)[arity - 1];
//			it++;
//			for (; it != range_end; it++) {
////				const RamDomain* data = *(it);
////				auto curlat = data[arity-1];
//				// TODO
//				RamDomain curlat = (*it)[arity - 1];
//				// set 2 input variables
//				std::vector<RamDomain> args = { biggestLat, curlat };
//				ctxt_temp.setArguments(args);
//
//				// evaluate binary constraint
//				for (const auto& cas : lub_func.getLatCase()) {
//					if (cas.match == nullptr
//							|| interpreter.evalCond(*cas.match, ctxt_temp)) {
//						// get output if match
//						res = interpreter.evalVal(*cas.output, ctxt_temp);
//						break;
//					}
//				}
////				biggestLat = latAssoc->applyLub(biggestLat, curlat);
//			}
//			high[arity - 1] = biggestLat;
//
//			insert(high);
//			other.insert(high);
//		}
//	}
	/** Purge table */
	void purge() {
		blockList.clear();
		for (const auto& cur : indices) {
			cur.second->purge();
		}
		num_tuples = 0;
	}

	/** get index for a given set of keys using a cached index as a helper. Keys are encoded as bits for each
	 * column */
	InterpreterIndex* getIndex(const SearchColumns& key,
			InterpreterIndex* cachedIndex) const {
		if (!cachedIndex) {
			return getIndex(key);
		}
		return getIndex(cachedIndex->order());
	}

	/** get index for a given set of keys. Keys are encoded as bits for each column */
	InterpreterIndex* getIndex(const SearchColumns& key) const {
		// suffix for order, if no matching prefix exists
		std::vector<unsigned char> suffix;
		suffix.reserve(getArity());

		// convert to order
		InterpreterIndexOrder order;
		for (size_t k = 1, i = 0; i < getArity(); i++, k *= 2) {
			if (key & k) {
				order.append(i);
			} else {
				suffix.push_back(i);
			}
		}

		// see whether there is an order with a matching prefix
		InterpreterIndex* res = nullptr;
		{
			auto lease = lock.acquire();
			(void) lease;

			for (auto it = indices.begin(); !res && it != indices.end(); ++it) {
				if (order.isCompatible(it->first)) {
					res = it->second.get();
				}
			}
		}
		// if found, use compatible index
		if (res) {
			return res;
		}

		// extend index to full index
		for (auto cur : suffix) {
			order.append(cur);
		}
		assert(order.isComplete());

		// get a new index
		return getIndex(order);
	}

	/** get index for a given order. Keys are encoded as bits for each column */
	InterpreterIndex* getIndex(const InterpreterIndexOrder& order) const {
		// TODO: improve index usage by re-using indices with common prefix
		InterpreterIndex* res = nullptr;
		{
			auto lease = lock.acquire();
			(void) lease;
			auto pos = indices.find(order);
			if (pos == indices.end()) {
				std::unique_ptr<InterpreterIndex>& newIndex = indices[order];
				newIndex = std::make_unique<InterpreterIndex>(order);
				newIndex->insert(this->begin(), this->end());
				res = newIndex.get();
			} else {
				res = pos->second.get();
			}
		}
		return res;
	}

	/** Obtains a full index-key for this relation */
	SearchColumns getTotalIndexKey() const {
		return (1 << (getArity())) - 1;
	}

	/** check whether a tuple exists in the relation */
	bool exists(const RamDomain* tuple) const {
		// handle arity 0
		if (getArity() == 0) {
			return !empty();
		}

		// handle all other arities
		if (!totalIndex) {
			totalIndex = getIndex(getTotalIndexKey());
		}
		return totalIndex->exists(tuple);
	}

	// --- iterator ---

	/** Iterator for relation */
	class iterator: public std::iterator<std::forward_iterator_tag, RamDomain*> {
	public:
		iterator() = default;

		iterator(const InterpreterRelation* const relation) :
				relation(relation), tuple(
						relation->arity == 0 ?
								reinterpret_cast<RamDomain*>(this) :
								&relation->blockList[0][0]) {
		}

		const RamDomain* operator*() {
			return tuple;
		}

		bool operator==(const iterator& other) const {
			return tuple == other.tuple;
		}

		bool operator!=(const iterator& other) const {
			return (tuple != other.tuple);
		}

		iterator& operator++() {
			// support 0-arity
			if (relation->arity == 0) {
				tuple = nullptr;
				return *this;
			}

			// support all other arities
			++index;
			if (index == relation->num_tuples) {
				tuple = nullptr;
				return *this;
			}

			int blockIndex = index / (BLOCK_SIZE / relation->arity);
			int tupleIndex = (index % (BLOCK_SIZE / relation->arity))
					* relation->arity;

			tuple = &relation->blockList[blockIndex][tupleIndex];
			return *this;
		}

	private:
		const InterpreterRelation* const relation = nullptr;
		size_t index = 0;
		RamDomain* tuple = nullptr;
	};

	/** get iterator begin of relation */
	inline iterator begin() const {
		// check for emptiness
		if (empty()) {
			return end();
		}

		return iterator(this);
	}

	/** get iterator begin of relation */
	inline iterator end() const {
		return iterator();
	}

	/** Extend tuple */
	virtual std::vector<RamDomain*> extend(const RamDomain* tuple) {
		std::vector<RamDomain*> newTuples;

		// A standard relation does not generate extra new knowledge on insertion.
		newTuples.push_back(new RamDomain[2] { tuple[0], tuple[1] });

		return newTuples;
	}

	/** Extend relation */
	virtual void extend(const InterpreterRelation& rel) {
	}

private:
	/** Arity of relation */
	const size_t arity;

	/** Size of blocks containing tuples */
	static const int BLOCK_SIZE = 1024;

	/** Number of tuples in relation */
	size_t num_tuples;

	std::deque<std::unique_ptr<RamDomain[]>> blockList;

	/** List of indices */
	mutable std::map<InterpreterIndexOrder, std::unique_ptr<InterpreterIndex>> indices;

	/** Total index for existence checks */
	mutable InterpreterIndex* totalIndex;

	/** Lock for parallel execution */
	mutable Lock lock;
};

/**
 * Interpreter Equivalence Relation
 */

class InterpreterEqRelation: public InterpreterRelation {
public:
	InterpreterEqRelation(size_t relArity) :
			InterpreterRelation(relArity) {
	}

	/** Insert tuple */
	void insert(const RamDomain* tuple) override {
		// TODO: (pnappa) an eqrel check here is all that appears to be needed for implicit additions
		// TODO: future optimisation would require this as a member datatype
		// brave soul required to pass this quest
		// // specialisation for eqrel defs
		// std::unique_ptr<binaryrelation> eqreltuples;
		// in addition, it requires insert functions to insert into that, and functions
		// which allow reading of stored values must be changed to accommodate.
		// e.g. insert =>  eqRelTuples->insert(tuple[0], tuple[1]);

		// for now, we just have a naive & extremely slow version, otherwise known as a O(n^2) insertion
		// ):

		for (auto* newTuple : extend(tuple)) {
			InterpreterRelation::insert(newTuple);
			delete[] newTuple;
		}
	}

	/** Find the new knowledge generated by inserting a tuple */
	std::vector<RamDomain*> extend(const RamDomain* tuple) override {
		std::vector<RamDomain*> newTuples;

		newTuples.push_back(new RamDomain[2] { tuple[0], tuple[0] });
		newTuples.push_back(new RamDomain[2] { tuple[0], tuple[1] });
		newTuples.push_back(new RamDomain[2] { tuple[1], tuple[0] });
		newTuples.push_back(new RamDomain[2] { tuple[1], tuple[1] });

		std::vector<const RamDomain*> relevantStored;
		for (const RamDomain* vals : *this) {
			if (vals[0] == tuple[0] || vals[0] == tuple[1]
					|| vals[1] == tuple[0] || vals[1] == tuple[1]) {
				relevantStored.push_back(vals);
			}
		}

		for (const auto vals : relevantStored) {
			newTuples.push_back(new RamDomain[2] { vals[0], tuple[0] });
			newTuples.push_back(new RamDomain[2] { vals[0], tuple[1] });
			newTuples.push_back(new RamDomain[2] { vals[1], tuple[0] });
			newTuples.push_back(new RamDomain[2] { vals[1], tuple[1] });
			newTuples.push_back(new RamDomain[2] { tuple[0], vals[0] });
			newTuples.push_back(new RamDomain[2] { tuple[0], vals[1] });
			newTuples.push_back(new RamDomain[2] { tuple[1], vals[0] });
			newTuples.push_back(new RamDomain[2] { tuple[1], vals[1] });
		}

		return newTuples;
	}
	/** Extend this relation with new knowledge generated by inserting all tuples from a relation */
	void extend(const InterpreterRelation& rel) override {
		std::vector<RamDomain*> newTuples;
		// store all values that will be implicitly relevant to the those that we will insert
		for (const auto* tuple : rel) {
			for (auto* newTuple : extend(tuple)) {
				newTuples.push_back(newTuple);
			}
		}
		for (const auto* newTuple : newTuples) {
			InterpreterRelation::insert(newTuple);
			delete[] newTuple;
		}
	}
};

}  // end of namespace souffle
