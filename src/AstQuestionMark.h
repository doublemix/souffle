/************************************************************************
 *
 * @file AstQuestionMark.h
 *
 *	by: Qing Gong
 * Define the classes AstQuestionMark to represent the question
 * mark operator.
 * Isolate this class because if it's declared in AstArgument.h, it will cause
 * mutual include issue between AstArgument.h and AstLiteral.h
 *
 ***********************************************************************/

#pragma once

#include "AstLiteral.h"

namespace souffle {

/**
 * An argument representing conditional ternary operation:
 * Comparing two argument, and return a value based on the result.
 * eg:
 * 		x=y ? x+2 : "Bot"
 */
class AstQuestionMark: public AstArgument {
public:
//	/**
//	 * Binary Comparing Operators in the condition part, referred to BinaryConstraintOp
//	 */
//	enum class CompOp {
//		__UNDEFINED__,  // undefined operator
//		EQ,             // equivalence of two values
//		NE,             // whether two values are different
//		LT,             // less-than
//		LE,             // less-than-or-equal-to
//		GT,             // greater-than
//		GE,             // greater-than-or-equal-to
//	};
//
//	/**
//	 * Converts operator to its symbolic representation
//	 */
//	inline std::string toBinaryCompareSymbol(CompOp op) const {
//		switch (op) {
//		case CompOp::EQ:
//			return "=";
//		case CompOp::NE:
//			return "!=";
//		case CompOp::LT:
//			return "<";
//		case CompOp::LE:
//			return "<=";
//		case CompOp::GT:
//			return ">";
//		case CompOp::GE:
//			return ">=";
//		default:
//			break;
//		}
//		assert(false && "Unsupported Binary Comparing Operator!");
//		return "?";
//	}

	/** Creates a new Ast question mark node */
	AstQuestionMark(BinaryConstraintOp Op, std::unique_ptr<AstArgument> arg1,
			std::unique_ptr<AstArgument> arg2) {
		cond = std::make_unique<AstBinaryConstraint>(Op, std::move(arg1),
				std::move(arg2));
	}

	/** Destructor */
	~AstQuestionMark() override = default;

	// -- getters and setters --

	const AstBinaryConstraint* getBinaryConstraint() const {
		return cond.get();
	}

	const AstArgument* getFirstReturn() const {
		return ret1.get();
	}

	const AstArgument* getSecondReturn() const {
		return ret2.get();
	}

	void setReturns(std::unique_ptr<AstArgument> r1,
			std::unique_ptr<AstArgument> r2) {
		assert(ret1==nullptr && ret2==nullptr);
		ret1 = std::move(r1);
		ret2 = std::move(r2);
	}

	// -- others --

	/** Prints this instance in a parse-able format */
	void print(std::ostream& os) const override {
		os << *cond;
		os << " ? " << *ret1 << " : " << *ret2;
	}

	/** Obtains a list of all embedded child nodes */
	std::vector<const AstNode*> getChildNodes() const override {
		auto res = AstArgument::getChildNodes();
		res.push_back(cond.get());
		res.push_back(ret1.get());
		res.push_back(ret2.get());
		return res;
	}

	/** Creates a clone of this AST sub-structure */
	AstQuestionMark* clone() const override {
		auto res = new AstQuestionMark(cond->getOperator(),
				std::unique_ptr<AstArgument>(cond->getLHS()->clone()),
				std::unique_ptr<AstArgument>(cond->getRHS()->clone()));
		res->setReturns(std::unique_ptr<AstArgument>(ret1->clone()),
				std::unique_ptr<AstArgument>(ret2->clone()));
		res->setSrcLoc(getSrcLoc());
		return res;
	}

	/** Mutates this node */
	void apply(const AstNodeMapper& map) override {
		//TODO
	}

protected:
	/** Implements the node comparison for this node type */
	bool equal(const AstNode& node) const override {
		assert(nullptr != dynamic_cast<const AstQuestionMark*>(&node));
		const auto& other = static_cast<const AstQuestionMark&>(node);
		return cond == other.cond && equal_ptr(ret1, other.ret1)
				&& equal_ptr(ret2, other.ret2);
	}

private:
	/** The binary constraint in the condition */
	std::unique_ptr<AstBinaryConstraint> cond;

	/** The arguments to return **/
	std::unique_ptr<AstArgument> ret1;
	std::unique_ptr<AstArgument> ret2;
};

}  // end of namespace souffle
