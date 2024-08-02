#pragma once

#include "math/vectors/vector3.hpp"
#include "matrix.hpp"

namespace FunEngine::Math {
template <typename TYPE = double>
class Matrix4x4 final : public Matrix<TYPE, 4, 4> {
public:
  Vector3<TYPE> get_position() {
    return Vector3<TYPE>(this->values[3][0], this->values[3][1],
                         this->values[3][2]);
  }
  /*
    TYPE get_determinant() {
      if (!this->cache.is_determinant_dirty)
        return this->cache.determinant;
    }*/

  void set_position(TYPE x_axis, TYPE y_axis, TYPE z_axis) {
    this->set(3, 0, x_axis);
    this->set(3, 1, y_axis);
    this->set(3, 2, z_axis);
  }

  void set_position(Vector3<TYPE> &vector) {
    this->set(3, 0, vector[0]);
    this->set(3, 1, vector[1]);
    this->set(3, 2, vector[2]);
  }
};
} // namespace FunEngine::Math
