/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 1143 - Longest Common Subsequence
 * @approach Using a recursive DP approach
 * @date 29-09-2022
 * 
 * Runtime - 1358 ms
 * Memory Usage - 102.7 MB
 */
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  map<pair<int, int>, int> dp;  // maps position p,q to largest subsequence
                                // possible from that position to the end

  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();

    return helper(text1, text2, 0, 0);
  }

  int helper(string& s1, string& s2, int p, int q) {
    if (p == s1.size() || q == s2.size()) return 0;

    if (dp.find({p, q}) != dp.end()) return dp[{p, q}];

    if (s1[p] == s2[q])
      dp[{p, q}] = 1 + helper(s1, s2, p + 1, q + 1);

    else
      dp[{p, q}] = max(helper(s1, s2, p, q + 1), helper(s1, s2, p + 1, q));

    return dp[{p, q}];
  }
};

int main() {
  Solution sol = Solution();
  // "etzupkr"
  // "ubmrapg"
  string a = "etzupkr", b = "ubmrapg";

  cout << sol.longestCommonSubsequence(a, b) << endl;
}