/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 14 - Longest Common Prefix
 * @approach simple
 * @date 12-01-2023
 * 
 * Runtime - 0 ms O(m * n)
 * Memory Usage - 9.3 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfPrefix(vector<string>& strs, int minLength) {
    for (int i = 0; i < minLength; i++) {
      char currChar = strs[0][i];

      int j = 1;
      while (j < strs.size()) {
        if (currChar != strs[j][i]) return i;
        j++;
      }
    }

    return minLength;
  }
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];

    int minLength = INT_MAX;
    for (int i = 0; i < strs.size(); i++) {
      minLength = min(minLength, (int)strs[0].size());
    }

    int len = lengthOfPrefix(strs, minLength);
    return strs[0].substr(0, len);
  }
};