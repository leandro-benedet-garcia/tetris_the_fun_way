#pragma once

#include <limits>

namespace FunEngine::Math {
template <typename TYPE>
bool approximately(TYPE left, TYPE right,
                   float tolerance = std::numeric_limits<TYPE>::epsilon()) {
  return ((left - right) < tolerance) && ((right - left) < tolerance);
}

template <typename TYPE, typename FUNCTION_TYPE>
TYPE sigma(TYPE values, FUNCTION_TYPE function) {
  TYPE curr_sum = 0;

  for (auto curr_value : values)
    curr_sum += function(curr_value);

  return curr_sum;
}

} // namespace FunEngine::Math
