#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>
#include <vector>

using namespace std;

namespace FunEngine {
class EngineObject {
private:
  static vector<int> used_ids;
  static int last_id;

public:
  int id;
  string name;

  EngineObject(string name);
  static int get_next_id();
};
} // namespace FunEngine
#endif
