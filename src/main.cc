#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "palindrome.h"
#include "sorting.h"

int main() {
  std::string s = "OiTeSeTiO";
  std::cout << s << " " << (isPalindromePtr(s) ? "is" : "is not") << " a palindrome" << std::endl;

  bool res;

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  for (int i = 0; i < 10000000; i++) {
    res = isPalindromePtr(s);
  }
  std::cout << res << std::endl;
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_s = end - start;

  std::cout << elapsed_s.count() << std::endl;


  std::string longStr = "aizajSdozdjaoAiiiidAsajkdjqUjzjjjjjUzkkksdqqq";
  std::cout << longestPalindromeMap(longStr) << std::endl;

  std::vector<float> o = { 31.0, 41.0, 59.0, 26.0, 41.0, 58.0 };
  insertionSort(o);

  for (auto i = o.begin(); i != o.end(); ++i) {
    std::cout << *i << ' ';
  }

  return 0;
}
