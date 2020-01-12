/************************************************************************
 *
 * @file RamLatticeFunctor.h
 *	added by Qing Gong
 *
 * Defines class for call to lattice function
 *
 ************************************************************************/
#pragma once

#include "RamLatticeBinaryFunction.h"

namespace souffle {
/**
 * Lattice functor
 */
class RamLatticeFunctor: public RamValue {
public:
	RamLatticeFunctor(RamNodeType type) :
			RamValue(type) {
	}
};

/**
 * Lattice binary functor: different from glb, it can only
 * support two arguments, instead of larger or equal to two
 */
class RamLatticeBinaryFunctor: public RamLatticeFunctor {
private:
	std::string name;

//	struct Ref_st {
//		int identifier;
//		int element;
//		std::unique_ptr<RamRelationReference> relation { nullptr };
//
//		Ref_st() = default;
//
//		Ref_st(int ident, int elem, std::unique_ptr<RamRelationReference> rel =
//				nullptr) :
//				identifier(ident), element(elem), relation(std::move(rel)) {
//		}
//
//		Ref_st(const Ref_st& ref) :
//				identifier(ref.identifier), element(ref.element) {
//			if (ref.relation != nullptr) {
//				relation = std::unique_ptr<RamRelationReference>(
//						ref.relation->clone());
//			}
//		}
//
//		Ref_st& operator=(Ref_st other) {
//			identifier = other.identifier;
//			element = other.element;
//			relation = std::move(other.relation);
//			return *this;
//		}
//
//		bool operator==(const Ref_st& ref) const {
//			return identifier == ref.identifier && element == ref.element;
//		}
//	};
	/** pair of identifier and element number for referenced lattice elements **/
//	Ref_st ref1;
//	Ref_st ref2;
	std::unique_ptr<RamValue> ref1;
	std::unique_ptr<RamValue> ref2;

	std::shared_ptr<RamLatticeBinaryFunction> func;

	/** Lattice Definition **/
	//std::unique_ptr<RamLatticeAssociation> lattice;
	/** Relation */
	//std::unique_ptr<RamRelationReference> relation;
public:

	RamLatticeBinaryFunctor(std::string n) :
			RamLatticeFunctor(RN_LatticeBinaryFunctor), name(n) {
	}
	RamLatticeBinaryFunctor(std::string n, std::unique_ptr<RamValue> r1,
			std::unique_ptr<RamValue> r2) :
			RamLatticeFunctor(RN_LatticeBinaryFunctor), name(n), ref1(
					std::move(r1)), ref2(std::move(r2)) {
	}

	/** Print */
	void print(std::ostream& os) const override {
		os << name << "( ";
		os << *ref1;
		os << ", ";
		os << *ref2;
		os << " )";
//		os << "t" << ref1.identifier << "."
//				<< (ref1.relation)->getArg(ref1.element);
//		os << ", t" << ref2.identifier << "."
//				<< (ref2.relation)->getArg(ref2.element);
//		os << " )";
	}

//	void setRef1(int identifier, int element,
//			std::unique_ptr<RamRelationReference> relation) {
//		ref1 = {identifier, element, std::move(relation)};
//	}
//
//	void setRef2(int identifier, int element,
//			std::unique_ptr<RamRelationReference> relation) {
//		ref2 = {identifier, element, std::move(relation)};
//	}

	void setRef(std::unique_ptr<RamValue> r1, std::unique_ptr<RamValue> r2) {
		ref1 = std::move(r1);
		ref2 = std::move(r2);
	}

//	const Ref_st* getRef1() const {
//		return &ref1;
//	}
//
//	const Ref_st* getRef2() const {
//		return &ref2;
//	}

	const RamValue* getRef1() const {
		return ref1.get();
	}

	const RamValue* getRef2() const {
		return ref2.get();
	}

//	const RamLatticeAssociation* getLatticeAssociation() const {
//		return lattice.get();
//	}

	void setFunc(std::shared_ptr<RamLatticeBinaryFunction> f) {
		func = f;
	}

	const RamLatticeBinaryFunction& getFunc() {
		return *func;
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		return std::vector<const RamNode*>();  // no child nodes
	}

	/** Create clone */
	RamLatticeBinaryFunctor* clone() const override {
		return new RamLatticeBinaryFunctor(name,
				std::unique_ptr<RamValue>(ref1->clone()),
				std::unique_ptr<RamValue>(ref2->clone()));
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		//TODO
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamLatticeBinaryFunctor*>(&node));
		const auto& other = static_cast<const RamLatticeBinaryFunctor&>(node);
		return name == other.name && ref1.get() == other.ref1.get()
				&& ref2.get() == other.ref2.get();
	}
};

}  // end of namespace souffle
