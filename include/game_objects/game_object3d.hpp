#pragma once

#include "game_object.hpp"
#include "math/matrices/matrix4x4.hpp"

using namespace std;

namespace FunEngine {
class GameObject3d : public GameObject {
public:
  Math::Matrix4x4<double> global_position;

  void set_global_position(double x_axis, double y_axis,
                           double z_axis);
};
} // namespace FunEngine
