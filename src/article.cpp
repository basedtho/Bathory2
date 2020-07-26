#include "article.hpp"
#include <ncurses.h>

#define FEED_TITLE_LENGTH 20

std::size_t strlen_utf8(const std::string &str) {
  std::size_t length = 0;
  for (char c : str) {
    if ((c & 0xC0) != 0x80) {
      ++length;
    }
  }
  return length;
}

void Article::truncate_feed(std::string feed) {
  std::string res{};
  for (auto i = 0; static_cast<size_t>(i) < feed.length() &&
                   strlen_utf8(res) != FEED_TITLE_LENGTH + 1;
       i++) {
    res.push_back(feed[i]);
  }
  if (strlen_utf8(res) == FEED_TITLE_LENGTH + 1) {
    res.pop_back();
  }
  while (strlen_utf8(res) < FEED_TITLE_LENGTH) {
    res.push_back(' ');
  }
  truncated_feed = res;
}

void Article::extend_title(std::string title) {
  while (title.length() + 6 + 1 + FEED_TITLE_LENGTH + 1 <
         static_cast<size_t>(COLS)) {
    title.push_back(' ');
  }
  while (title.length() + 6 + 1 + FEED_TITLE_LENGTH + 1 >
         static_cast<size_t>(COLS)) {
    title.pop_back();
  }
  extended_title = title;
}

void Article::resize() { extend_title(title); }
