
#pragma once

#include "constants.hpp"
#include <array>
#include <cassert>
#include <cstddef>

#define ParentMatrix Matrix<TYPE, SIZE_X, SIZE_Y>

namespace FunEngine::Math {
template <typename TYPE = floating_type, size_t SIZE_X = 2, size_t SIZE_Y = 2>
class Matrix {
public:
  std ::array<TYPE, SIZE_X * SIZE_Y> values{};

  Matrix(std ::array<TYPE, SIZE_X * SIZE_Y> items) { this->values = items; }

  ParentMatrix *transpose;

#if __cplusplus >= 202302L
  TYPE &operator[](size_t index_x, size_t index_y) {
    assert(index_x < SIZE_X && index_y < SIZE_Y);
    return values[index_y * SIZE_X + index_x];
  }
#endif

  TYPE get(size_t index_x, size_t index_y) {
    assert(index_x < SIZE_X && index_y < SIZE_Y);
    return values[index_y * SIZE_X + index_x];
  }

  void set(size_t index_x, size_t index_y, TYPE value) {
    assert(index_x < SIZE_X && index_y < SIZE_Y);
    values[index_y * SIZE_X + index_x] = value;
  }

  Matrix() {
    for (size_t x = 0; x < SIZE_X; x++)
      for (size_t y = 0; y < SIZE_Y; y++)
        set(x, y, x == y ? 1 : 0);
  }
};
} // namespace FunEngine::Math
