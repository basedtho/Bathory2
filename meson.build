project('bathory2', 'cpp')
dep = [dependency('CURL')]
dep += [dependency('ncursesw')]
dep += [dependency('pugixml')]
dep += [dependency('fmt')]
executable('bathory2', 'src/main.cpp', 'src/article.cpp', 'src/feed.cpp', 'src/window.cpp', dependencies : dep)
