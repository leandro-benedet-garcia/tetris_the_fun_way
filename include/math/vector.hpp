#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "./constants.hpp"

#include <cmath>
#include <vector>
namespace FunEngine::Math {
template <typename T = __precision, unsigned short int SIZE = 1> class Vector {
public:
  /// multiply elements one by one
  static T pi_notation(const std::vector<T> values) {
    T curr_value = values[0];

    if (SIZE == 1)
      return curr_value;

    for (int i = 1; i < SIZE; i++)
      curr_value *= values[i];

    return curr_value;
  }

  static T magnitude(const std::vector<T> values) {
    T curr_sum = 0;

    for (T curr_value : values)
      curr_sum += pow(curr_value, 2);

    return sqrt(curr_sum);
  }

  static T angle_to(const std::vector<T> from, const std::vector<T> to) {
    T sums = pi_notation(from) + pi_notation(to);
    T magnitudes = magnitude(from) * magnitude(to);
    return acos(sums / magnitudes);
  }
};
} // namespace FunEngine::Math
#endif
