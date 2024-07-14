#include <iostream>
#include <math/vector.hpp>

namespace math = FunEngine::Math;

int main() {
  int *values = new int[2]{1, 2};
  std::cout << math::Vector<int>::magnitude(values);
}
