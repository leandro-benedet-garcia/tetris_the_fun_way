#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include "constants.hpp"
#include "vector.hpp"

namespace FunEngine::Math {
template <typename T = __precision> class Vector3 final : public Vector<T, 3> {

public:
  using Vector<T, 3>::Vector;

  Vector3(T x_axis, T y_axis, T z_axis)
      : Vector<T, 3>({x_axis, y_axis, z_axis}) {}

  T get_x() { return this->values[0]; }
  T get_y() { return this->values[1]; }
  T get_z() { return this->values[2]; }

  void set_x(T value) { this->values[0] = value; }
  void set_y(T value) { this->values[1] = value; }
  void set_z(T value) { this->values[2] = value; }
};
} // namespace FunEngine::Math
#endif
