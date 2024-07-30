#pragma once

#include "scene.hpp"

using namespace std;

namespace FunEngine {
class SceneManager : EngineObject {
public:
  Scene active_scene;

  SceneManager();
};
} // namespace FunEngine
