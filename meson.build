project('Plank', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++2a'])

run_target('lint',
  command : ['cpplint', '--recursive', '--exclude', 'build/*', '.'])

run_target('format',
  command : [
    'clang-format',
    '-i',
    '--verbose',
    'engine.cpp',
    'transition.cpp',
    'main.cpp',
    'player.cpp',
    'machine_state.cpp',
    'include/engine.h',
    'include/transition.h',
    'include/player.h',
    'include/machine_state.h'])

executable('Plank',
           'engine.cpp',
           'transition.cpp',
           'main.cpp', 'player.cpp',
           'machine_state.cpp',
           install : true)
