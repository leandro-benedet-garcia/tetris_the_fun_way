#pragma once

#include <type_traits>
namespace FunEngine::Math {
template <class TYPE>
concept Numeric = std::is_arithmetic_v<TYPE>;
}
