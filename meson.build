project(
  'fun_engine',
  'cpp',
  'cython',
  version: '0.1.0',
  default_options: ['cpp_std=c++23'],
)
add_global_arguments(['-fPIC', '-Wall'], language: 'cpp')

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
package_ver = conf_data.get('version')

configure_file(input: 'config.h.in', output: 'config.h', configuration: conf_data)

py_install = import('python').find_installation(pure: false)

pybind11_dep = dependency('pybind11')
# tomlplusplus = dependency('tomlplusplus')

inc = include_directories(['include', '.'])

lib = shared_library(
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
  'funenginepy',
  [
    'python_module/vector2.cpp',
  ],
  install: true,
  dependencies: [pybind11_dep],
  link_with: lib,
  include_directories: inc,
)

import('pkgconfig').generate(
  libraries: lib,
  version: '0.1.0',
  name: 'libfunengine',
  description: 'A game engine',
)
