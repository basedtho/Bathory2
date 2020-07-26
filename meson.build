project('bathory', 'cpp')
dep = [dependency('CURL')]
dep += [dependency('ncursesw')]
dep += [dependency('pugixml')]
dep += [dependency('fmt')]
executable('bathory', 'src/main.cpp', 'src/article.cpp', 'src/feed.cpp', 'src/window.cpp', dependencies : dep)
