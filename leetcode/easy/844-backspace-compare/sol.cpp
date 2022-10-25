/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 844 - Backspace String Compare
 * @date 25-10-2022
 * 
 * Runtime - 4 ms O(m + n)
 * Memory Usage - 6.3 MB O(n)
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  string finalResult(string s) {
    string res;

    for (auto &c : s) {
      if (c == '#') {
        if (!res.empty()) res.pop_back();
      }

      else {
        res.push_back(c);
      }
    }

    return res;
  }

  bool backspaceCompare(string s, string t) {
    return finalResult(s) == finalResult(t);
  }
};