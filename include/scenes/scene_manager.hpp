#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "scene.hpp"

using namespace std;

namespace FunEngine {
class SceneManager: EngineObject {
public:
  Scene active_scene;
};
} // namespace FunEngine
#endif
