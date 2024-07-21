#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <algorithm>
#include <array>
#include <cmath>
#include <initializer_list>
#include <vector>

namespace FunEngine::Math {
template <typename T = float, size_t SIZE = 1> class Vector {
public:
  std::array<T, SIZE> values;

  Vector(std::vector<T> vec) {
    std::copy_n(vec.begin(), SIZE, values.begin());
  }

  Vector(std::initializer_list<T> init) {
    std::copy_n(init.begin(), SIZE, values.begin());
  }

  T &operator[](size_t idx) { return values[idx]; }

  /// multiply elements one by one
  T pi_notation() {
    T curr_value = values[0];

    if (SIZE == 1)
      return curr_value;

    for (size_t i = 1; i < SIZE; i++)
      curr_value *= values[i];

    return curr_value;
  }

  T magnitude() {
    T curr_sum = 0;

    for (auto curr_value : values)
      curr_sum += pow(curr_value, 2);

    return sqrt(curr_sum);
  }

  T angle_to(Vector<T, SIZE> to) {
    T sums = this->pi_notation() + to.pi_notation();
    T magnitudes = this->magnitude() * to.magnitude();
    return acos(sums / magnitudes);
  }
};
} // namespace FunEngine::Math
#endif
