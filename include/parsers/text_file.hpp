#ifndef TEXT_FILE_HPP
#define TEXT_FILE_HPP

#include <fstream>

using namespace std;

namespace FunEngine {
class TextFile {
private:
  ifstream file;

public:
  TextFile(const char *file_name, const char *open_mode);
  string get_full_file();
};
}; // namespace FunEngine
#endif
