project('bathory2', 'cpp', default_options : ['cpp_std=c++17'])
dep = [dependency('CURL')]
dep += [dependency('curses')]
dep += [dependency('fmt')]
incdir = [include_directories('third_party/pugixml/src')]
executable(
  'bathory2',
  'src/main.cpp',
  'src/article.cpp',
  'src/feed.cpp',
  'src/window.cpp',
  'third_party/pugixml/src/pugixml.cpp',
  dependencies : dep,
  include_directories : incdir )
