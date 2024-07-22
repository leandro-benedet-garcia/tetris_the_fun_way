#include "math/vectors/vector3.hpp"
#include <iostream>

int main() {
  FunEngine::Math::Vector3<double> vec(10.0, 10.0, 10.0);
  std::cout << vec.magnitude() << "\n";
}
