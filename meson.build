project(
  'conways-game-of-life',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

dependencies = [
  dependency('sdl3')
]

sources = [
  'src/color.c',
  'src/gol.c',
  'src/tile.c'
]

exe = executable(
  'gol',
  sources: sources,
  dependencies : dependencies,
  install : true,
  include_directories: include_directories('include')
)

test('basic', exe)
