#include "object.hpp"

namespace FunEngine {
int EngineObject::get_next_id() { return last_id + 1; }
EngineObject::EngineObject(string name) { this->name = name; }
} // namespace FunEngine
