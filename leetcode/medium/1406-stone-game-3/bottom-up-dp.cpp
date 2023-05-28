/**
 * @file bottom-up-dp.cpp
 * @author Vortexx2
 * @brief Problem 1406 - Stone Game 3
 * @approach Using bottom up DP
 * @date 28-05-2023
 * 
 * Runtime - 244 ms O(n)
 * Memory Usage - 132.3 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string stoneGameIII(vector<int>& s) {
    int n = s.size();
    vector<int> dp(n + 1);

    dp[n - 1] = s[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      int ans = INT_MIN;

      ans = max(ans, s[i] - dp[i + 1]);
      if (i + 1 < n) ans = max(ans, s[i] + s[i + 1] - dp[i + 2]);
      if (i + 2 < n) ans = max(ans, s[i] + s[i + 1] + s[i + 2] - dp[i + 3]);

      dp[i] = ans;
    }

    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";

  }
};