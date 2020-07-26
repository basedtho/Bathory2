#pragma once

#include <string>

class Article {
public:
  Article(std::string const &date, std::string const &feed, std::string title)
      : date(date), feed(feed), title(title) {
    resize();
  };
  std::string date;
  std::string truncated_feed;
  std::string extended_title;
  void resize();

private:
  std::string feed;
  std::string title;
  void truncate_feed(std::string feed);
  void extend_title(std::string title);
};
