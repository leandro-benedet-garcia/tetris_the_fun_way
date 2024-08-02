#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "engine_object.hpp"
#include "math/vectors/vector2.hpp"
#include "math/vectors/vector3.hpp"
#include "math/vectors/vector4.hpp"

namespace py = pybind11;
namespace fun = FunEngine;
namespace math = FunEngine::Math;

template <math::Numeric TYPE>
void declare_vector2(py::module &m, const std::string &type_name) {
  using Class = math::Vector2<TYPE>;
  std::string pyclass_name = "Vector2" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def(py::init<TYPE &, TYPE &>())
      .def("angle", &Class::angle)
      .def("angle_to", &Class::angle_to)
      .def("magnitude", &Class::magnitude)
      .def("__repr__", &Class::to_string);
}

template <math::Numeric TYPE>
void declare_vector3(py::module &m, const std::string &type_name) {
  using Class = math::Vector3<TYPE>;
  std::string pyclass_name = "Vector3" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def(py::init<TYPE &, TYPE &, TYPE &>())
      .def("angle_to", &Class::angle_to)
      .def("magnitude", &Class::magnitude)
      .def("__repr__", &Class::to_string);
}

template <math::Numeric TYPE>
void declare_vector4(py::module &m, const std::string &type_name) {
  using Class = math::Vector4<TYPE>;
  std::string pyclass_name = "Vector4" + type_name;
  py::class_<Class>(m, pyclass_name.c_str())
      .def(py::init<TYPE &, TYPE &, TYPE &, TYPE &>())
      .def("angle_to", &Class::angle_to)
      .def("magnitude", &Class::magnitude)
      .def("__repr__", &Class::to_string);
}

PYBIND11_MODULE(funenginepy, m) {
  py::class_<fun::EngineObject>(m, "EngineObject")
      .def(py::init<const std::string &>());

  auto math_module = m.def_submodule("math");

  math_module.def("approximately", &math::approximately<double>,
                  "Compare two floating points together", py::arg("left"),
                  py::arg("right"),
                  py::arg("tolerance") =
                      std::numeric_limits<double>::epsilon());

  declare_vector2<double>(math_module, "");
  declare_vector2<int>(math_module, "Int");

  declare_vector3<double>(math_module, "");
  declare_vector3<int>(math_module, "Int");

  declare_vector4<double>(math_module, "");
  declare_vector4<int>(math_module, "Int");
}
