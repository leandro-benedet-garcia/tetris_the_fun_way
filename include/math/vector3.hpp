#ifndef VECTOR3_HPP
#define VECTOR3_HPP
#include "constants.hpp"
#include <cmath>
#include <immintrin.h>
#include <typeinfo>

namespace FunEngine::Math {
template <typename T = __precision> class Vector3 final {
private:
  T values[3];
  __m256d double_simd;
  bool is_dirty = true;

  inline void update_simd() {
    if (!is_dirty)
      return;

    if (typeid(T) == typeid(double))
      double_simd = _mm256_load_pd(values);

    is_dirty = false;
  }

public:
  T &operator[](unsigned short int idx) { return values[idx]; }

  T angle() { return atan2(values[1], values[0]); }

  Vector3(T x_axis, T y_axis, T z_axis) {
    values[0] = x_axis;
    values[1] = y_axis;
    values[2] = z_axis;
  }

  T get_x() { return values[0]; }
  T get_y() { return values[1]; }
  T get_z() { return values[2]; }

  void set_x(T value) {
    values[0] = value;
    is_dirty = true;
  }

  void set_y(T value) {
    values[1] = value;
    is_dirty = true;
  }

  void set_z(T value) {
    values[2] = value;
    is_dirty = true;
  }

  T magnitude() {
    T curr_sum = 0;

    if (typeid(T) == typeid(double)) {
      update_simd();
      __m256d simd = _mm256_mul_pd(double_simd, double_simd);
      for (int i = 0; i < 3; i++)
        curr_sum += simd[i];
    } else {
      for (T curr_value : this->values)
        curr_sum += pow(curr_value, 2);
    }
    return sqrt(curr_sum);
  }
};
} // namespace FunEngine::Math
#endif
