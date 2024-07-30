#pragma once
#include <string>
#include <unordered_set>

namespace FunEngine {
class EngineObject {
private:
  static std::unordered_set<int> used_instanced_ids;
  static std::unordered_set<int> used_prefab_ids;
  static int last_instance_id;

public:
  int id = 0;
  int prefab_id = 0;

  std::string name;

  EngineObject(const std::string &obj_name);
};
} // namespace FunEngine
