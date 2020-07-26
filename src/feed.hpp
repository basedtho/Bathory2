#pragma once

#include "article.hpp"
#include <curl/curl.h>
#include <string>
#include <vector>

class Feed {
public:
  explicit Feed(std::string const &url);
  std::vector<Article> articles;
  void resize();

private:
  void parse_buffer();
  std::string read_buffer;
  static size_t write_cb_static(void *contents, size_t size, size_t nmemb,
                                void *userp) {
    static_cast<Feed *>(userp)->write_cb(contents, size, nmemb);
    return nmemb * size;
  }
  size_t write_cb(void *contents, size_t size, size_t nmemb);
};
