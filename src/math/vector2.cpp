#include "math/vector2.hpp"
#include <cmath>
#include <immintrin.h>
#include <typeinfo>

using namespace std;

namespace FunEngine::Math {
template <typename T> T Vector2<T>::angle() { return atan2(this[1], this[0]); }

template <typename T> T Vector2<T>::get_x() { return values[0]; }
template <typename T> void Vector2<T>::set_x(T value) { values[0] = value; }

template <typename T> T Vector2<T>::magnitude() {
  T curr_sum = 0;

  if (typeid(T) == typeid(float)) {
    __m128 simd = _mm_load_ps(this->values);
    simd = _mm_mul_ps(simd, simd);
    for (int i = 0; i <= 2; i++)
      curr_sum += simd[i];
    if (typeid(T) == typeid(double)) {
      __m128d simd = _mm_load_pd(this->values);
      simd = _mm_mul_pd(simd, simd);
      for (int i = 0; i <= 2; i++)
        curr_sum += simd[i];
    } else {
      for (T curr_value : this->values)
        curr_sum += pow(curr_value, 2);
    }
    return sqrt(curr_sum);
  }
}
} // namespace FunEngine::Math