project(
  'fun_engine',
  'cpp',
  version: '0.1.0',
  default_options: ['cpp_std=c++23,c++20', 'warning_level=3'],
)

build_python_module = get_option('python_module')
build_executable = get_option('executable')

compiler = meson.get_compiler('cpp')

if not compiler.check_header('format')
  error('Compiler does not have the format header available, update your compiler')
endif

add_global_arguments(
  [
    '-msse',
    '-msse2',
    '-msse3',
    '-msse4.1',
    '-msse4.2',
  ],
  language: 'cpp',
)

if host_machine.system() == 'emscripten'
  add_global_arguments(
    [
      '-msimd128',
    ],
    language: 'cpp',
  )
else
  add_global_arguments(
    [
      '-mavx',
      '-mavx2',
    ],
    language: 'cpp',
  )
endif

if compiler.get_id() != 'msvc'
  add_global_arguments(
    [
      '-fno-fast-math',
      '-fno-unsafe-math-optimizations',
      '-Wfatal-errors',
      '-Wno-gnu-anonymous-struct',
    ],
    language: 'cpp',
  )
endif

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
    dependencies: [pybind11_dep, lib_deps],
    include_directories: inc,
  )
endif

if build_executable
  executable('funengine', ['src/main.cpp'], install: true, link_with: lib)
endif

import('pkgconfig').generate(
  libraries: lib,
  version: '0.1.0',
  name: 'libfunengine',
  description: 'A game engine',
)
