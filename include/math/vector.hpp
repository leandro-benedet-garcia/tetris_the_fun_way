#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cstddef>
#include <nmmintrin.h>

#include "./constants.hpp"

namespace FunEngine {
namespace Math {
template <typename T = __precision> class Vector {
public:
  /// multiply elements one by one
  static T pi_notation(T values[]);

  static T magnitude(T values[]);

  static T angle_to(const Vector<T> *other);
};
} // namespace Math
} // namespace FunEngine
#endif
