project('Plank', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++2a'])

run_target('lint',
  command : ['cpplint', '--recursive', '--exclude', 'build/*', '.'])

executable('Plank',
           'engine.cpp',
           'transition.cpp',
           'main.cpp', 'player.cpp',
           'machine_state.cpp',
           install : true)
