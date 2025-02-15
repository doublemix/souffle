/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2014, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file InterpreterIndex.h
 *
 * An index is implemented either as a hash-index, a double-hash, as a
 * red-black tree or as a b-tree. The choice of the implementation is
 * set by preprocessor defines.
 *
 ***********************************************************************/

#pragma once

#include <utility>

#include "BTree.h"
#include "RamTypes.h"
#include "Util.h"

namespace souffle {

/**
 * A class describing the sorting order of tuples within an index.
 */
class InterpreterIndexOrder {
public:
	// -- constructors --

	InterpreterIndexOrder(
			std::vector<unsigned char> order = std::vector<unsigned char>()) :
			columns(std::move(order)) {
	}

	InterpreterIndexOrder(const InterpreterIndexOrder&) = default;
	InterpreterIndexOrder(InterpreterIndexOrder&&) = default;

	// -- assignment operations --

	InterpreterIndexOrder& operator=(const InterpreterIndexOrder&) = default;
	InterpreterIndexOrder& operator=(InterpreterIndexOrder&&) = default;

	// -- other operations --

	/** Provides access to the order of columns */
	unsigned char operator[](std::size_t pos) const {
		return columns[pos];
	}

	/** Enables orders to be the key of a set or map */
	bool operator<(const InterpreterIndexOrder& other) const {
		return columns < other.columns;
	}

	// -- other members --

	/** Append an additional column to the end of this order */
	void append(unsigned char column) {
		assert(!contains(columns, column));
		columns.push_back(column);
	}

	/** Provides access to the size of this order */
	std::size_t size() const {
		return columns.size();
	}

	/** Determines whether the given column is covered or not */
	bool covers(unsigned char column) const {
		return contains(columns, column);
	}

	/** Tests whether the given order covers a complete list of columns */
	bool isComplete() const {
		// the columns must contain the values 0 ... |length|
		for (unsigned i = 0; i < columns.size(); i++) {
			if (!contains(columns, i)) {
				return false;
			}
		}
		return true;
	}

	/** Tests whether this order is a prefix of the given order. */
	bool isPrefixOf(const InterpreterIndexOrder& other) const {
		// this one must not be longer
		if (columns.size() > other.columns.size()) {
			return false;
		}
		for (unsigned i = 0; i < columns.size(); i++) {
			if (columns[i] != other.columns[i]) {
				return false;
			}
		}
		return true;
	}

	/**
	 * Tests whether this order is compatible with the given order. A
	 * order A is compatible with an order B if the first |A| elements
	 * of B are a permutation of A.
	 */
	bool isCompatible(const InterpreterIndexOrder& other) const {
		// this one must be shorter
		if (columns.size() > other.columns.size()) {
			return false;
		}
		// check overlapping prefix
		for (unsigned i = 0; i < columns.size(); ++i) {
			if (!contains(columns, other.columns[i])) {
				return false;
			}
		}
		return true;
	}

	/** Enables the index order to be printed */
	void print(std::ostream& out) const {
		out << "["
				<< join(columns, ",", [](std::ostream& out, int i) {out << i;})
				<< "]";
	}

	friend std::ostream& operator<<(std::ostream& out,
			const InterpreterIndexOrder& order) {
		order.print(out);
		return out;
	}
	// the order of columns along which fields should be sorted by an index
	std::vector<unsigned char> columns;
};

/* B-Tree indexes as default implementation for indexes */
class InterpreterIndex {
public:
	/* lexicographical comparison operation on two tuple pointers */
	struct comparator {
		const InterpreterIndexOrder& order;

		/* constructor to initialize state */
		comparator(const InterpreterIndexOrder& order) :
				order(order) {
		}

		/* comparison function */
		int operator()(const RamDomain* x, const RamDomain* y) const {
			for (size_t i = 0; i < order.size(); i++) {
				if (x[order[i]] < y[order[i]]) {
					return -1;
				}
				if (x[order[i]] > y[order[i]]) {
					return 1;
				}
			}
			return 0;
		}

		/* less comparison */
		bool less(const RamDomain* x, const RamDomain* y) const {
			return operator()(x, y) < 0;
		}

		/* equal comparison */
		bool equal(const RamDomain* x, const RamDomain* y) const {
			for (size_t i = 0; i < order.size(); i++) {
				if (x[order[i]] != y[order[i]]) {
					return false;
				}
			}
			return true;
		}
	};

	/* btree for storing tuple pointers with a given lexicographical order */
	using index_set = btree_multiset<const RamDomain*, comparator, std::allocator<const RamDomain*>, 512>;

	using iterator = index_set::iterator;

	InterpreterIndex(InterpreterIndexOrder order) :
			theOrder(std::move(order)), set(comparator(theOrder),
					comparator(theOrder)) {
	}

	const InterpreterIndexOrder& order() const {
		return theOrder;
	}

	/**
	 * add tuple to the index
	 *
	 * precondition: tuple does not exist in the index
	 */
	void insert(const RamDomain* tuple) {
		set.insert(tuple);
	}

	/**
	 * add tuples to the index via an iterator
	 *
	 * precondition: the tuples do not exist in the index
	 */
	template<class Iter>
	void insert(const Iter& a, const Iter& b) {
		set.insert(a, b);
	}
	;

	/** check whether tuple exists in index */
	bool exists(const RamDomain* value) {
		return set.find(value) != set.end();
	}

	/** purge all hashes of index */
	void purge() {
		set.clear();
	}

	/** enables the index to be printed */
	void print(std::ostream& out) const {
		set.printStats(out);
		out << "\n";
		set.printTree(out);
	}

	iterator begin() {
		return set.begin();
	}

	iterator end() {
		return set.end();
	}

	/** return start and end iterator of an equal range */
	inline std::pair<iterator, iterator> equalRange(
			const RamDomain* value) const {
		return lowerUpperBound(value, value);
	}

	/** return start iterator of a range */
	inline iterator LowerBound(const RamDomain* low) const {
		return set.lower_bound(low);
	}

	/** return end iterator of a range */
	inline iterator UpperBound(const RamDomain* high) const {
		return set.upper_bound(high);
	}
	/** return start and end iterator of a range */
	inline std::pair<iterator, iterator> lowerUpperBound(const RamDomain* low,
			const RamDomain* high) const {
		return std::pair<iterator, iterator>(set.lower_bound(low),
				set.upper_bound(high));
	}

private:
	// retain the index order used to construct an object of this class
	const InterpreterIndexOrder theOrder;
	// set storing tuple pointers of table
	index_set set;
};

}  // end of namespace souffle
