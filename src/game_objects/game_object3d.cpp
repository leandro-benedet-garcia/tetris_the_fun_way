#include "game_objects/game_object3d.hpp"

namespace FunEngine {
void GameObject3d::set_global_position(floating_type x_axis,
                                       floating_type y_axis,
                                       floating_type z_axis) {
  global_position.set_position(x_axis, y_axis, z_axis);
}
} // namespace FunEngine
