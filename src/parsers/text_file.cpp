#include "parsers/text_file.hpp"

#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>

using namespace std;

namespace FunEngine {
TextFile::TextFile(const char *file_name, const char *open_mode) {
  if (strcmp(open_mode, "w"))
    file = ifstream(file_name, ios_base::out);
  else if (strcmp(open_mode, "r"))
    file = ifstream(file_name, ios_base::in);
  else if (strcmp(open_mode, "r+") || strcmp(open_mode, "w+"))
    file = ifstream(file_name);
}

string TextFile::get_full_file() {
  file.seekg(0, ios::end);
  size_t size = file.tellg();
  string buffer(size, ' ');
  file.seekg(0);
  file.read(&buffer[0], size);
  return buffer;
}
} // namespace FunEngine
