#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include "../constants.hpp"
#include "vector.hpp"
#include <cmath>
#include <immintrin.h>

namespace FunEngine::Math {
template <typename T = __precision> class Vector2 final : public Vector<T, 2> {
public:
  using Vector<T, 2>::Vector;
  Vector2(T x_axis, T y_axis) : Vector<T, 2>({x_axis, y_axis}) {}

  T get_x() { return this->values[0]; }
  T get_y() { return this->values[1]; }

  void set_x(T value) { this->values[0] = value; }
  void set_y(T value) { this->values[1] = value; }

  T angle() { return atan2(this->values[1], this->values[0]); }
};
} // namespace FunEngine::Math
#endif
