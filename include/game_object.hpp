#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <vector>

#include "engine_object.hpp"

using namespace std;

namespace FunEngine {
class GameObject: EngineObject {
public:
  GameObject *parent;
  vector<GameObject> children;
};
} // namespace FunEngine
#endif
