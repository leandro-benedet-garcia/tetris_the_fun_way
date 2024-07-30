#include <type_traits>
namespace FunEngine::Math {
template <class T>
concept Numeric = std::is_arithmetic_v<T>;
}
