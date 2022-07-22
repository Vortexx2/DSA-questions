/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 91 - Decode Ways
 * @approach Iterative DP
 * @date 22-07-2022
 * 
 * Runtime - 3 ms
 * Memory Usage - 6.6 MB 
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int charToInt(char digit) { return digit - '0'; }

  int numDecodings(string s) {
    map<int, int> dp = {{s.size(), 1}};

    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '0')
        dp[i] = 0;

      else {
        int res = dp[i + 1];

        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && charToInt(s[i + 1]) <= 6)))
          res += dp[i + 2];

        dp[i] = res;
      }
    }

    return dp[0];
  }
};
