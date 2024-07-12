project('fun_engine', 'cpp', 'cython', version: '0.1.0', default_options:['cpp_std=c++22'])
add_global_arguments('-fPIC', language : 'cpp')

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
package_ver = conf_data.get('version')

pymod = import('python')

configure_file(input: 'config.h.in', output: 'config.h', configuration: conf_data)

py_install = pymod.find_installation(pure: false)
py_dep = py_install.dependency(embed: true)

pybind11 = dependency('pybind11')
# tomlplusplus = dependency('tomlplusplus')


inc = include_directories(['include', '.', py_install.get_path('include')])

lib = library(
  'funengine',
  [
    'src/math/vector.cpp',
    'src/math/vector2.cpp',
    ],
  # dependencies: deps,
  version: package_ver,
  include_directories: inc,
)

py_lib = py_install.extension_module(
  'funengine',
  [
    'python_module/vector2.cpp',
    ],
  install: true,
  dependencies: [py_dep, pybind11],
  link_with: lib,
  include_directories: inc,
)
