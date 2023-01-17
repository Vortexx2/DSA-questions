/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 926 - Flip String to Monotone Increasing
 * @approach Using DP
 * @date 17-01-2023
 * 
 * Runtime - 26 ms O(n)
 * Memory Usage - 11.2 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int right0 = 0, left1 = 0;
    for (auto& c : s) {
      if (c == '0') right0++;
    }

    int res = right0;
    for (auto& c : s) {
      if (c == '0') {
        right0--;
      } else {
        left1++;
      }
      res = min(res, left1 + right0);
    }

    return res;
  }
};