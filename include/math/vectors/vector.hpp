#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../constants.hpp"
#include "../utils.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include <vector>

namespace FunEngine::Math {
template <typename T = __precision, size_t SIZE = 1> class Vector {
public:
  std::array<T, SIZE> values;

  Vector(std::vector<T> vec) {
    std::copy_n(vec.begin(), SIZE, values.begin());
  }

  Vector(std::initializer_list<T> init) {
    std::copy_n(init.begin(), SIZE, values.begin());
  }

  T &operator[](size_t idx) { return values[idx]; }

  bool operator==(Vector<T, SIZE> other) {
    if (typeid(T) == typeid(int))
      throw std::logic_error("You can only compare vectors of type int, for "
                             "other types use approximately");
    for (size_t i; i < SIZE; i++)
      if (values[i] != other[i])
        return false;
    return true;
  }

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

  bool approximately(Vector<T, SIZE> other,
                     T tolerance = std::numeric_limits<T>::epsilon()) {
    if (typeid(T) == typeid(int)) {
      return this == other;
    } else {
      for (size_t i; i < SIZE; i++)
        if (!FunEngine::Math::approximately<T>(values[i], other[i], tolerance))
          return false;
    }
    return true;
  }
};
} // namespace FunEngine::Math
#endif
