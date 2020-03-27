/************************************************************************
 *
 * @file EnumTypeMask.h
 * added by: Qing Gong
 *
 ***********************************************************************/

#pragma once

#include <ostream>
#include <vector>

namespace souffle {

class EnumTypeMask {
public:
	EnumTypeMask(size_t arity) :
			mask(arity), number_mask(arity) {
		for (size_t i=0; i<arity; i++) {
			mask[i] = false;
			number_mask[i] = false;
		}
	}

	EnumTypeMask(std::initializer_list<bool> symbolList) :
			mask(symbolList) {
	}

	size_t getArity() const {
//		assert(mask.size() == number_mask.size());
		return mask.size();
	}

	bool isEnumType(size_t index) const {
		return index < getArity() && mask[index];
	}

	void setEnumType(size_t index, bool value = true) {
		assert(index < getArity());
		mask[index] = value;
	}

	// check if a Enum type include number type
	bool is_Enum_hasNUMBER(size_t index) const {
		return index < getArity() && number_mask[index];
	}

	void set_Enum_hasNUMBER(size_t index, bool value = true) {
		assert(index < getArity());
		number_mask[index] = value;
	}

	bool operator==(const EnumTypeMask& other) const {
		return mask == other.mask && number_mask == other.number_mask;
	}

	bool operator!=(const EnumTypeMask& other) const {
		return mask != other.mask || number_mask != other.number_mask;
	}

	void print(std::ostream& out) const {
		auto cur = mask.begin();
		if (cur == mask.end()) {
			return;
		}

		out << *cur++;
		for (; cur != mask.end(); ++cur) {
			out << ", " << *cur;
		}
	}

	friend std::ostream& operator<<(std::ostream& out,
			const EnumTypeMask& mask) {
		mask.print(out);
		return out;
	}

protected:
	std::vector<bool> mask;
	std::vector<bool> number_mask;
};

} /* namespace souffle */
