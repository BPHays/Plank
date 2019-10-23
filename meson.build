project('Plank', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++2a'])

incdir = include_directories('include')

boost_dep = dependency('boost')
gtest_dep = dependency('gtest', main: true, required: false)

executable('Plank',
           'main.cpp',
           'automaton/machine_state.cpp',
           'automaton/transition.cpp',
           'engine/engine.cpp',
           'engine/player.cpp',
           dependencies: boost_dep
           include_directories: incdir,
           install : true)

t = executable('ComponentsTest',
               'tests/components/test_die.cpp',
               'tests/components/test_cards.cpp',
               dependencies: gtest_dep,
               include_directories: incdir)

test('gtest test', t)
