project(
  'fun_engine',
  'cpp',
  version: '0.1.0',
  default_options: ['warning_level=3'],
)

if host_machine.system() == 'emscripten'
  add_global_arguments(['-msimd128', '-std=c++20'], language: 'cpp')
else
  add_global_arguments(
    [
      '-std=c++23',
      '-fPIC',
      '-Wno-gnu-anonymous-struct',
      '-Wfatal-errors',
      '-fno-fast-math',
      '-fno-unsafe-math-optimizations',
      '-mavx',
      '-mavx2',
      '-msse2',
      '-msse3',
      '-msse4.1',
      '-msse4.2',
    ],
    language: 'cpp',
  )
endif

compiler = meson.get_compiler('cpp')
build_python_module = get_option('python_module')

if compiler.get_id() == 'clang'
  add_global_arguments(
    [
      '-fdenormal-fp-math=ieee',
    ],
    language: 'cpp',
  )
elif compiler.get_id() == 'gcc'
  add_global_arguments(
    [
      '-ffloat-store',
    ],
    language: 'cpp',
  )
endif

sources = [
  'src/engine_object.cpp',
  'src/game_objects/game_object3d.cpp',
]

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
package_ver = conf_data.get('version')

configure_file(input: 'config.h.in', output: 'config.h', configuration: conf_data)

inc = include_directories(['include', '.'])

lib = static_library(
  'funengine',
  sources,
  # dependencies: deps,
  include_directories: inc,
)
lib_deps = declare_dependency(include_directories: inc, link_with: lib)
# tomlplusplus = dependency('tomlplusplus')

if build_python_module
  py_install = import('python').find_installation()

  pybind11_dep = dependency('pybind11')


  py_lib = py_install.extension_module(
    'funenginepy',
    sources: [
      'python_module/module.cpp',
    ],
    install: true,
    link_with: lib,
    dependencies: pybind11_dep,
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
