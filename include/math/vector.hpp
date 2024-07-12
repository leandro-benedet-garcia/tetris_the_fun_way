#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cstddef>
#include <nmmintrin.h>

#include "./constants.hpp"

namespace FunEngine::Math {
template <typename T = __precision, size_t vec_size = 1> class Vector {
private:
  void error_on_size_difference(Vector<T, vec_size> other);

public:
  const size_t SIZE = vec_size;

  T vec_values[vec_size];
  T operator[](int index);

  Vector(T values[vec_size]);

  /// multiply elements one by one
  T pi_notation();
  T magnitude();
  T angle_to(const Vector<T, vec_size> &other);
};
} // namespace FunEngine::Math
#endif
