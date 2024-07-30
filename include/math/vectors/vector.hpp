#pragma once

#include "../constants.hpp"
#include "../utils.hpp"
#include "constants.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <format>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>

namespace FunEngine::Math {
template <Numeric TYPE = floating_type, size_t SIZE = 1> class Vector {
public:
  std::array<TYPE, SIZE> values{};
  Vector(std::vector<TYPE> vec) {
    std::copy_n(vec.begin(), SIZE, values.begin());
  }

  TYPE &operator[](size_t idx) { return values[idx]; }

  bool operator==(Vector<TYPE, SIZE> &other) {
    if (typeid(TYPE) != typeid(int))
      throw std::logic_error("You can only compare vectors of type int, for "
                             "other types use approximately");
    for (size_t i; i < SIZE; i++)
      if (values[i] != other[i])
        return false;
    return true;
  }

  std::string to_string() {
    auto vec_str = std::format("Vector{}(", SIZE);
    for (size_t i = 0; i < SIZE; i++) {
      vec_str += std::to_string(values[i]);
      if (i < SIZE - 1)
        vec_str += ", ";
    }

    vec_str += ")";
    return vec_str;
  }

  /// multiply elements one by one
  FORCE_INLINE TYPE pi_notation() {
    auto curr_value = values[0];

    if (SIZE == 1)
      return curr_value;

    for (size_t i = 1; i < SIZE; i++)
      curr_value *= values[i];

    return curr_value;
  }

  FORCE_INLINE TYPE magnitude() {
    TYPE curr_sum = 0;

    for (auto curr_value : values)
      curr_sum += pow(curr_value, 2);

    return sqrt(curr_sum);
  }

  /// magnitude, but clamped to speed of light
  FORCE_INLINE TYPE velocity() {
    auto mag = magnitude();
    return mag < LIGHT_SPEED ? mag : LIGHT_SPEED;
  }

  FORCE_INLINE TYPE angle_to(Vector<TYPE, SIZE> to) {
    auto sums = this->pi_notation() + to.pi_notation();
    auto magnitudes = this->magnitude() * to.magnitude();
    return acos(sums / magnitudes);
  }

  FORCE_INLINE bool
  approximately(Vector<TYPE, SIZE> other,
                TYPE tolerance = std::numeric_limits<TYPE>::epsilon()) {
    if (typeid(TYPE) == int_id)
      return this == other;
    else
      for (size_t i; i < SIZE; i++)
        if (!FunEngine::Math::approximately<TYPE>(values[i], other[i],
                                                  tolerance))
          return false;

    return true;
  }
};
} // namespace FunEngine::Math
