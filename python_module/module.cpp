#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "engine_object.hpp"
#include "math/vector2.hpp"
#include "math/vector3.hpp"

namespace py = pybind11;
namespace fun = FunEngine;
namespace math = FunEngine::Math;

template <typename T>
void declare_vector(py::module &m, const std::string &type_name) {
  using Class = math::Vector2<T>;
  std::string pyclass_name = "Vector" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      //.def("pi_notation", &Class::pi_notation)
      .def("magnitude", &Class::magnitude)
      .def("angle_to", &Class::angle);
}

template <typename T>
void declare_vector2(py::module &m, const std::string &type_name) {
  using Class = math::Vector2<T>;
  std::string pyclass_name = "Vector2" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def("angle", &Class::angle)
      .def("magnitude", &Class::magnitude);
}

template <typename T>
void declare_vector3(py::module &m, const std::string &type_name) {
  using Class = math::Vector3<T>;
  std::string pyclass_name = "Vector3" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def("angle", &Class::angle)
      .def("magnitude", &Class::magnitude);
}

PYBIND11_MODULE(funenginepy, m) {
  py::class_<fun::EngineObject>(m, "EngineObject")
      .def(py::init<const std::string &>());

  auto math_module = m.def_submodule("math");

  declare_vector<float>(math_module, "Float");
  declare_vector<double>(math_module, "");
  declare_vector<int>(math_module, "Int");

  declare_vector2<float>(math_module, "Float");
  declare_vector2<double>(math_module, "");
  declare_vector2<int>(math_module, "Int");

  declare_vector3<float>(math_module, "Float");
  declare_vector3<double>(math_module, "");
  declare_vector3<int>(math_module, "Int");
}
