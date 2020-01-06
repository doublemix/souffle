/************************************************************************
 *
 * @file RamQuestionMark.h
 *
 *	by: Qing Gong
 *
 * Defines a class for evaluating Question Mark in the Relational Algebra
 * Machine.
 * Isolate this class because if it is declared in RamValue.h, it will cause
 * mutual include issue between RamValue.h and RamCondition.h
 *
 ***********************************************************************/

#pragma once

#include "RamCondition.h"

namespace souffle {

/**
 * Access a question mark operator, which contains a condition,
 * and two return arguments.
 */
class RamQuestionMark: public RamValue {
private:
	std::unique_ptr<RamCondition> cond;
	std::unique_ptr<RamValue> ret1;
	std::unique_ptr<RamValue> ret2;

public:
	RamQuestionMark(std::unique_ptr<RamCondition> cd,
			std::unique_ptr<RamValue> r1, std::unique_ptr<RamValue> r2) :
			RamValue(RN_QuestionMark), cond(move(cd)), ret1(move(r1)), ret2(
					move(r2)) {
	}

	const RamCondition& getCondition() const {
		return *cond;
	}

	const RamValue& getFirstRet() const {
		return *ret1;
	}

	const RamValue& getSecondRet() const {
		return *ret2;
	}

	/** Print */
	void print(std::ostream& os) const override {
		os << *cond;
		os << " ? " << *ret1 << " : " << *ret2;
	}

	/** Obtain list of child nodes */
	std::vector<const RamNode*> getChildNodes() const override {
		// TODO
		return std::vector<const RamNode*>();
	}

	/** Create clone */
	RamQuestionMark* clone() const override {
		return new RamQuestionMark(std::unique_ptr<RamCondition>(cond->clone()),
				std::unique_ptr<RamValue>(ret1->clone()),
				std::unique_ptr<RamValue>(ret2->clone()));
	}

	/** Apply mapper */
	void apply(const RamNodeMapper& map) override {
		//todo
	}

protected:
	/** Check equality */
	bool equal(const RamNode& node) const override {
		assert(nullptr != dynamic_cast<const RamQuestionMark*>(&node));
		const auto& other = static_cast<const RamQuestionMark&>(node);
		return cond.get() == other.cond.get() && ret1.get() == other.ret1.get()
				&& ret2.get() == other.ret2.get();
	}
};

}  // end of namespace souffle
