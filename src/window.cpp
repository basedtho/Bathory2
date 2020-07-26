#include "window.hpp"
#include <fmt/core.h>
#include <ncurses.h>

Window::Window() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  // nodelay(stdscr, TRUE);
  getmaxyx(stdscr, height, width);
}

Window::~Window() { endwin(); }
