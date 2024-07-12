#ifndef VECTOR2_HPP
#define VECTOR2_HPP
#include "vector.hpp"

namespace FunEngine::Math {
template <typename T = __precision> class Vector2 final : Vector<T> {
public:
  T values[2];
  Vector2(T x, T y);
  T get_x();
  T get_y();

  void set_x(T value);
  void set_y(T value);
  T magnitude();
  T angle();
};
} // namespace FunEngine::Math
#endif
