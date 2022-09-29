/**
 * @file bottom-up-dp.cpp
 * @author Vortexx2
 * @brief Problem 1143 - Longest Common Subsequence
 * @approach Using a bootom up DP approach
 * @date 29-09-2022
 * 
 * Runtime - 35 ms
 * Memory Usage - 13 MB
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (text1[i] == text2[j]) {
          dp[i][j] = dp[i + 1][j + 1] + 1;
        }

        else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }

    return dp[0][0];
  }
};

int main() {
  string s1 = "abcde", s2 = "axe";
  Solution sol = Solution();
  cout << sol.longestCommonSubsequence(s1, s2) << endl;
}