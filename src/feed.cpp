#include "feed.hpp"
#include <iostream>
#include <pugixml.hpp>

Feed::Feed(std::string const &url) {
  CURL *hnd;
  hnd = curl_easy_init();
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.71.1");
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
  curl_easy_setopt(hnd, CURLOPT_WRITEDATA, this);
  curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, write_cb_static);
  curl_easy_perform(hnd);
  curl_easy_cleanup(hnd);
  parse_buffer();
}

size_t Feed::write_cb(void *contents, size_t size, size_t nmemb) {
  size_t real_size = size * nmemb;
  read_buffer.append((const char *)contents, real_size);
  return real_size;
}

void Feed::parse_buffer() {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(read_buffer.c_str());
  if (result) {
    for (auto a : doc.child("rss").child("channel").children("item")) {
      Article article{
          a.child("pubDate").text().as_string(),
          doc.child("rss").child("channel").child("title").text().as_string(),
          a.child("title").text().as_string()};
      articles.push_back(article);
    }
  }
}

void Feed::resize() {
  for (auto a : articles) {
    a.resize();
  }
}
