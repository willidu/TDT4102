project('testproject', 'cpp',
  version : '0.1',
  default_options : ['warning_level=2',
                     'cpp_std=c++17',
                     'c_std=c17',
                     'default_library=static'])

# Windows compilation has no pre-packaged SDL2 available, and compilation takes a while.
# If you want to compile from source, remove everything but the contents of the else clause.
if host_machine.system() == 'windows'
  sdl2_dep = subproject('sdl2_windows').get_variable('sdl2_windows_dep')
else
  sdl2_dep = dependency('sdl2')
endif

animationwindow_dep = dependency('animationwindow', fallback: ['animationwindow', 'animationwindow_dep'])
# TODO: slett std_lib_facilities fra animationwindow. Kommenter samtidig ut de to følgende linjene
# std_lib_facilities_dep = dependency('std_lib_facilities', fallback: ['std_lib_facilities', 'std_lib_facilities_dep'])


src = ['main.cpp', 'task1.cpp', 'task2.cpp', 'task3.cpp', 'task4.cpp', 'task5.cpp']

exe = executable('program', src, dependencies : [animationwindow_dep, sdl2_dep], cpp_args : ['-Wconversion', '-fdiagnostics-color=always', '-Werror=return-type'])
# exe = executable('program', src, dependencies : [animationwindow_dep, sdl2_dep, ], cpp_args : '-Wconversion')
