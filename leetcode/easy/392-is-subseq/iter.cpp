/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 392 - Is Subsequence
 * @date 28-09-2022
 *
 * Runtime - 0 ms
 * Memory Usage - 6.4 MB
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int p1 = 0;

    for (const char c : t) {
      if (c == s[p1]) p1++;
    }

    return s.size() == p1;
  }
};