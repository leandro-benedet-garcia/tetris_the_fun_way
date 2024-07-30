#pragma once

#include "game_object.hpp"
#include "math/matrices/matrix4x4.hpp"

using namespace std;

namespace FunEngine {
class GameObject3d : public GameObject {
public:
  Math::Matrix4x4<floating_type> global_position;

  void set_global_position(floating_type x_axis, floating_type y_axis,
                           floating_type z_axis);
};
} // namespace FunEngine
