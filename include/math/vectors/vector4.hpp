#pragma once

#include "./vector.hpp"

namespace FunEngine::Math {
template <typename TYPE = floating_type>
class Vector4 final : public Vector<TYPE, 4> {

public:
  using Vector<TYPE, 4>::Vector;

  Vector4(TYPE x_axis, TYPE y_axis, TYPE z_axis, TYPE w_axis)
      : Vector<TYPE, 4>({x_axis, y_axis, z_axis, w_axis}) {}

  TYPE get_x() { return this->values[0]; }
  TYPE get_y() { return this->values[1]; }
  TYPE get_z() { return this->values[2]; }
  TYPE get_w() { return this->values[3]; }

  void set_x(TYPE value) { this->values[0] = value; }
  void set_y(TYPE value) { this->values[1] = value; }
  void set_z(TYPE value) { this->values[2] = value; }
  void set_w(TYPE value) { this->values[3] = value; }
};
} // namespace FunEngine::Math
