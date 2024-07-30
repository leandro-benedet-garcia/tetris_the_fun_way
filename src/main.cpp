#include "math/vectors/vector3.hpp"
#include <iostream>

int main() {
  FunEngine::Math::Vector3<double> vector{10, 10, 10};
  auto mag = vector.magnitude();
  std::cout << mag << "\n";
  return 0;
}
