#pragma once

#include "game_objects/game_object.hpp"


namespace FunEngine {
class Scene {
public:
  bool is_active;
  vector<GameObject> game_objects;
};
} // namespace FunEngine
