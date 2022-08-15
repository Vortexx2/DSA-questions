/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 516 - Longest Palindromic Subsequence
 * @approach Using a recursive DP top down approach
 * @date 15-08-2022
 * 
 * Runtime - 1876 ms
 * Memory Usage - 137.6 MB
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  string inp;
  // maps { (i, j) : maxLen }, where maxLen = the maximum length of subsequences
  // from index left to index right
  map<pair<int, int>, int> dp;

  int longestPalindromeSubseq(string s) {
    inp = s;
    return rec(0, s.size() - 1);
  }

  int rec(int left, int right) {
    if (left == right) return 1;

    if (dp.find({left, right}) != dp.end()) return dp[{left, right}];

    if (inp[left] == inp[right]) {
      if (right == left + 1)
        dp[{left, right}] = 2;

      else
        dp[{left, right}] = 2 + rec(left + 1, right - 1);
    }

    else
      dp[{left, right}] = max(rec(left, right - 1), rec(left + 1, right));

    return dp[{left, right}];
  }
};