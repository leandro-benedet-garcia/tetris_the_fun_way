#include "game_objects/game_object.hpp"

namespace FunEngine {
GameObject GameObject::get_child(size_t index) { return children[index]; }
} // namespace FunEngine
