project(
  'fun_engine',
  'cpp',
  version: '0.1.0',
  default_options: ['cpp_std=c++23', 'warning_level=3'],
)

build_python_module = get_option('python_module')

add_global_arguments(
  [
    '-fPIC',
    '-Wfatal-errors',
    '-mavx',
    '-mavx2',
    '-msse2',
    '-msse3',
    '-msse4.1',
    '-msse4.2',
  ],
  language: 'cpp',
)

sources = [
  'src/math/vectors/vector2.cpp',
  'src/math/vectors/vector3.cpp',
  'src/engine_object.cpp',
]

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
package_ver = conf_data.get('version')

configure_file(input: 'config.h.in', output: 'config.h', configuration: conf_data)

inc = include_directories(['include', '.'])

lib = shared_library(
  'funengine',
  sources,
  # dependencies: deps,
  version: package_ver,
  include_directories: inc,
)
lib_deps = declare_dependency(include_directories: inc, link_with: lib)
# tomlplusplus = dependency('tomlplusplus')

if build_python_module
  py_install = import('python').find_installation(pure: false)

  pybind11_dep = dependency('pybind11')

  py_lib = py_install.extension_module(
    'funenginepy',
    sources: [
      'python_module/module.cpp',
    ],
    install: true,
    link_with: lib,
    dependencies: [pybind11_dep, py_install.dependency(embed: true)],
    include_directories: inc,
  )
endif

executable(
  'funengine',
  ['src/main.cpp'],
  install: true,
  dependencies: lib_deps,
)

import('pkgconfig').generate(
  libraries: lib,
  version: '0.1.0',
  name: 'libfunengine',
  description: 'A game engine',
)
