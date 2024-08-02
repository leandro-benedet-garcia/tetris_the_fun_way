#include "game_objects/game_object3d.hpp"

namespace FunEngine {
void GameObject3d::set_global_position(double x_axis,
                                       double y_axis,
                                       double z_axis) {
  global_position.set_position(x_axis, y_axis, z_axis);
}
} // namespace FunEngine
