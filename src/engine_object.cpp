#define _GLIBCXX_USE_CXX11_ABI 0
#include "engine_object.hpp"
#include <string>

namespace FunEngine {
int EngineObject::last_instance_id = 0;

EngineObject::EngineObject(const std::string &obj_name) : name(obj_name) {}
} // namespace FunEngine
