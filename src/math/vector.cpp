#include <cmath>
#include <stdexcept>

#include "math/vector.hpp"

using namespace std;

namespace FunEngine::Math {
template <typename T, size_t vec_size>
T Vector<T, vec_size>::operator[](int index) {
  return this->values[index];
}

template <typename T, size_t vec_size>
Vector<T, vec_size>::Vector(T values[vec_size]) {
  for (int i = 0; i < vec_size; i++)
    this->values[i] = values[i];
}

template <typename T, size_t vec_size>
void Vector<T, vec_size>::error_on_size_difference(Vector<T, vec_size> other) {
  if (SIZE != other.SIZE)
    throw length_error("Vectors must have same size, left is {}, other is {}",
                       SIZE, other.SIZE);
}

template <typename T, size_t vec_size> T Vector<T, vec_size>::magnitude() {
  T curr_sum = 0;

  for (T curr_value : this->values)
    curr_sum += pow(curr_value, 2);

  return sqrt(curr_sum);
}

template <typename T, size_t vec_size> T Vector<T, vec_size>::pi_notation() {
  T curr_value = this->values[0];

  if (vec_size == 1)
    return curr_value;

  // Using regular loop because it needs to skip the first item
  for (int i = 1; i <= vec_size; i++)
    curr_value *= this->values[i];
}

template <typename T, size_t vec_size>
T Vector<T, vec_size>::angle_to(const Vector<T, vec_size> &other) {
  error_on_size_difference(other);

  T sums = pi_notation() + other.pi_notation();
  T magnitudes = magnitude() * other.magnitude();
  return acos(sums / magnitudes);
}
} // namespace FunEngine::Math
