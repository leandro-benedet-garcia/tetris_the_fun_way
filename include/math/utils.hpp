#include <limits>

namespace FunEngine::Math {
template <typename T>
bool approximately(T left, T right,
                   float tolerance = std::numeric_limits<T>::epsilon()) {
  return ((left - right) < tolerance) && ((right - left) < tolerance);
}
} // namespace FunEngine::Math
