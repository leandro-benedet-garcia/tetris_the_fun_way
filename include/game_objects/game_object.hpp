#pragma once

#include <vector>

#include "engine_object.hpp"

using namespace std;

namespace FunEngine {
class GameObject: EngineObject {
public:
  GameObject *parent;
  vector<GameObject> children;

  GameObject get_child(size_t index);
};
} // namespace FunEngine
