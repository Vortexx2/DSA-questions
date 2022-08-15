/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 516 - Longest Palindromic Subsequence
 * @date 15-08-2022
 *
 * Runtime - 201 ms O(n ^ 2)
 * Memory Usage - 73 MB O(n ^ 2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));

    int maxLen = 1;

    // length of the subsequence that we're considering is actually `len + 1`,
    // and all (i, i) pairs are automatically 1 so we start with length 2
    // substrings
    for (int len = 1; len < s.size(); len++) {
      for (int i = 0; i < s.size() - len; i++) {
        // if length of subsequence is greater than 1
        // first and last characters of the subsequence are the same
        if (s[i] == s[i + len]) {
          if (len == 1)
            dp[i][i + len] = 2;

          else
            dp[i][i + len] = 2 + dp[i + 1][i + len - 1];
        }

        else
          dp[i][i + len] = max(dp[i][i + len - 1], dp[i + 1][i + len]);

        maxLen = max(maxLen, dp[i][i + len]);
      }
    }

    return maxLen;
  }
};