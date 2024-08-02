#pragma once
#include "math/vectors/vector2.hpp"
#include "matrix.hpp"

namespace FunEngine::Math {
template <typename TYPE = double>
class Matrix3x3 final : public Matrix<TYPE, 3, 3> {
public:
  TYPE *a1 = *this[0, 0];
  TYPE *a2 = *this[0, 1];
  TYPE *a3 = *this[0, 2];

  TYPE *b1 = *this[1, 0];
  TYPE *b2 = *this[1, 1];
  TYPE *b3 = *this[1, 2];

  TYPE *c1 = *this[2, 0];
  TYPE *c2 = *this[2, 1];
  TYPE *c3 = *this[2, 2];

  Vector2<TYPE> get_position() {
    return Vector2<TYPE>(*this[3, 0], *this[3, 1]);
  }

  TYPE get_determinant() {
    if (!this->cache.is_determinant_dirty)
      return this->cache.determinant;
  }

  void set_position(TYPE x_axis, TYPE y_axis) {
    (*this)[2, 0] = x_axis;
    (*this)[2, 1] = y_axis;

    this->cache.set_all_dirty();
  }

  void set_position(Vector2<TYPE> &vector) {
    (*this)[2, 0] = vector[0];
    (*this)[2, 1] = vector[1];

    this->cache.set_all_dirty();
  }
};
} // namespace FunEngine::Math
