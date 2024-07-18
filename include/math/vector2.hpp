#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include "constants.hpp"
#include <cmath>
#include <immintrin.h>
#include <typeinfo>

namespace FunEngine::Math {
template <typename T = __precision> class Vector2 final {
private:
  T values[2];
  __m128d double_simd;
  bool is_dirty = true;

  inline void update_simd() {
    if (!is_dirty)
      return;

    if (typeid(T) == typeid(double))
      double_simd = _mm_load_pd(values);

    is_dirty = false;
  }

public:
  T &operator[](unsigned short int idx) { return values[idx]; }

  T angle() { return atan2(values[1], values[0]); }

  Vector2(T x_axis, T y_axis) {
    values[0] = x_axis;
    values[1] = y_axis;
  }

  T get_x() { return values[0]; }
  T get_y() { return values[1]; }

  void set_x(T value) {
    values[0] = value;
    is_dirty = true;
  }

  void set_y(T value) {
    values[1] = value;
    is_dirty = true;
  }

  T magnitude() {
    T curr_sum = 0;

    if (typeid(T) == typeid(double)) {
      update_simd();
      __m128d simd = _mm_mul_pd(double_simd, double_simd);
      for (int i = 0; i < 2; i++)
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
