#include <pybind11/pybind11.h>

#include "math/vector2.hpp"
#include "math/constants.hpp"

namespace py = pybind11;
namespace math = FunEngine::Math;

#define Vector2 math::Vector2<__precision>

PYBIND11_MODULE(funengine, v) {
    py::class_<Vector2>(v, "Vector2")
        .def(py::init<__precision &, __precision &>())
        .def_property("x", &Vector2::get_x, &Vector2::get_y);
}
