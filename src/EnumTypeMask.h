
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
	EnumTypeMask(size_t arity) : mask(arity) {}

	EnumTypeMask(std::initializer_list<bool> symbolList) : mask(symbolList) {}

    size_t getArity() const {
        return mask.size();
    }

    bool isEnumType(size_t index) const {
        return index < getArity() && mask[index];
    }

    void setEnumType(size_t index, bool value = true) {
        if (index < getArity()) {
            mask[index] = value;
        }
    }

    bool operator==(const EnumTypeMask& other) const {
        return mask == other.mask;
    }

    bool operator!=(const EnumTypeMask& other) const {
        return mask != other.mask;
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

    friend std::ostream& operator<<(std::ostream& out, const EnumTypeMask& mask) {
        mask.print(out);
        return out;
    }

protected:
    std::vector<bool> mask;
};

} /* namespace souffle */
