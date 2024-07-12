#ifndef SCENE_HPP
#define SCENE_HPP

#include "game_object.hpp"

using namespace std;

namespace FunEngine {
class Scene {
public:
  bool is_active;
  vector<GameObject> game_objects;
};
} // namespace FunEngine
#endif
