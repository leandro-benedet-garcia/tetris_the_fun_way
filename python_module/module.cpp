#include <pybind11/pybind11.h>

#include "engine_object.hpp"
#include "math/vector.hpp"

namespace py = pybind11;
namespace fun = FunEngine;
namespace math = FunEngine::Math;

template <typename T>
void declare_vectors(py::module &m, const std::string &type_name) {
  using Class = math::Vector<T>;
  std::string pyclass_name = "Vector" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def_static("pi_notation", Class::pi_notation)
      .def_static("magnitude", Class::magnitude)
      .def_static("angle_to", Class::angle_to);
}

PYBIND11_MODULE(funenginepy, m) {
  py::class_<fun::EngineObject>(m, "EngineObject")
      .def(py::init<const std::string &>());

  declare_vectors<float>(m, "Float");
  declare_vectors<double>(m, "");
  declare_vectors<int>(m, "Int");
}
