#include "feed.hpp"
#include "window.hpp"
#include <cstdio>
#include <locale>
#include <ncurses.h>

int main(int argc, char *argv[]) {
  std::setlocale(LC_ALL, "");
  Window win{};
  Feed feed{"https://hnrss.org/newest?comments=200&link=comments"};
  int ch{};
  int current{};
  do {
    switch (ch) {
    case 'q':
      return 0;
    case 'j':
      if (static_cast<size_t>(current) + 1 < feed.articles.size() &&
          current + 1 < LINES) {
        current++;
      }
      break;
    case 'k':
      if (current > 0) {
        current--;
      }
      break;
    case KEY_RESIZE:
      for (auto a : feed.articles) {
        a.resize();
      }
      break;
    }
    for (auto i = 0; static_cast<size_t>(i) < feed.articles.size() && i < LINES;
         ++i) {
      if (i == current) {
        attron(A_REVERSE);
      }
      mvprintw(i, 0, "%.6s│%s│%s", feed.articles[i].date.c_str(),
               feed.articles[i].truncated_feed.c_str(),
               feed.articles[i].extended_title.c_str());
      if (i == current) {
        attroff(A_REVERSE);
      }
    }
    refresh();
  } while ((ch = getch()));
  return 0;
}
