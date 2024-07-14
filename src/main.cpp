#include <iostream>
#include "math/vector.hpp"

int main() {
  int *values = new int[2]{1, 2};
  std::cout << FunEngine::Math::Vector<int>::magnitude(values);
}
