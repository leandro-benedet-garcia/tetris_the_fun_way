#pragma once

#include "./vector.hpp"

namespace FunEngine::Math {
template <Numeric TYPE = double>
class Vector3 final : public Vector<TYPE, 3> {
public:
  using Vector<TYPE, 3>::Vector;

  Vector3(TYPE x_axis, TYPE y_axis, TYPE z_axis)
      : Vector<TYPE, 3>({x_axis, y_axis, z_axis}) {}

  TYPE get_x() { return this->values[0]; }
  TYPE get_y() { return this->values[1]; }
  TYPE get_z() { return this->values[2]; }

  void set_x(TYPE value) { this->values[0] = value; }
  void set_y(TYPE value) { this->values[1] = value; }
  void set_z(TYPE value) { this->values[2] = value; }
};
} // namespace FunEngine::Math
