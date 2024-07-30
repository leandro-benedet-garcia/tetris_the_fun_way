#pragma once

#include "matrix.hpp"
#include <typeinfo>

namespace FunEngine::Math {
template <typename TYPE = floating_type>
class Matrix2x2 final : public Matrix<TYPE, 2, 2> {
public:
  TYPE *a1 = &this->values[0];
  TYPE *a2 = &this->values[1];
  TYPE *b1 = &this->values[2];
  TYPE *b2 = &this->values[3];

  FORCE_INLINE TYPE get_determinant() {
    if (!this->cache.is_determinant_dirty)
      return this->cache.determinant;

    if (this->cache.is_identity) {
      this->cache.set_determinant(1);
      return 1;
    }

    // if the columns are the same, the determinant will always be 0
    // but we are only doing the check if TYPE is int because floating point
    // comparison might be more expensive than to actually do the math
    if (typeid(TYPE) == int_id && a1 == a2 && b1 == b2) {
      this->cache.determinant = 0;
      return 0;
    }

    TYPE result = a1 * b1 - a2 * b2;
    this->cache.set_determinant(result);
    return result;
  }
};
} // namespace FunEngine::Math
