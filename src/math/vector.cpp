#include <cmath>
#include <stdexcept>

#include "math/vector.hpp"

using namespace std;

namespace FunEngine {
namespace Math {

template <typename T> T Vector<T>::magnitude(T values[]) {
  T curr_sum = 0;

  for (T curr_value : values)
    curr_sum += pow(curr_value, 2);

  return sqrt(curr_sum);
}

template <typename T> T Vector<T>::pi_notation(T values[]) {
  int vec_size = std::size(values);
  T curr_value = values[0];

  if (vec_size == 1)
    return curr_value;

  // Using regular loop because it needs to skip the first item
  for (int i = 1; i < vec_size; i++)
    curr_value *= values[i];
}

template <typename T> T Vector<T>::angle_to(const Vector<T> *other) {
  T sums = pi_notation() + other->pi_notation();
  T magnitudes = magnitude() * other->magnitude();
  return acos(sums / magnitudes);
}
} // namespace Math
} // namespace FunEngine
