/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 392 - Is Subsequence
 * @approach - Recursive
 * @date 28-09-2022
 * 
 * Runtime - 3 ms
 * Memory Usage - 6.2 MB
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int sSize = s.size(), tSize = t.size();

    return helper(s, t, sSize - 1, tSize - 1);
  }

  bool helper(string& s, string& t, int m, int n) {
    if (m == -1) return true;
    if (n == -1) return false;

    if (s[m] == t[n]) {
      return helper(s, t, m - 1, n - 1);
    }

    return helper(s, t, m, n - 1);
  }
};