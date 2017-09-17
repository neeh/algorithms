#include "palindrome.h"

#include <unordered_map>


// isPalindrome

bool isPalindrome(const std::string &str) {
  // 100%
  uint32_t l = 0;
  uint32_t r = str.size() - 1;
  while (r > l) {
    if (str[l++] != str[r--]) return false;
  }
  return true;
}

bool isPalindromePtr(const std::string &str) {
  // 67%
  const char *l = str.c_str();
  const char *r = l + str.size() - 1;
  while (r > l) {
    if (*l++ != *r--) return false;
  }
  return true;
}

bool isPalindromeIterator(const std::string &str) {
  // 1077%
  return str == std::string(str.rbegin(), str.rend());
}

bool isPalindromeEqual(const std::string &str) {
  // 363%
  return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}


// longestPalindrome

std::string longestPalindrome(const std::string &str) {
  if (isPalindrome(str)) {
    return str;
  } else {
    return str;
  }
}

std::string longestPalindromeMap(const std::string &str) {
  if (isPalindrome(str)) return str;

  std::unordered_map<char, uint32_t> cache;
  const char *p = str.c_str();
  const char *end = p + str.size();

  while (p < end) {
    if (cache.find(*p) != cache.end()) {
      cache[*p]++;
    } else {
      cache.insert(std::make_pair(*p, 0));
    }
    p++;
  }

  std::string out = "";

  for (std::pair<char, uint32_t> kv : cache) {
    char c = kv.first;
    uint32_t count = kv.second;

    while (count > 1) {
      out = c + out + c;
      count -= 2;
    }
  }

  return out;
}
