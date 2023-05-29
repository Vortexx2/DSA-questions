/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 877 - Stone Game
 * @approach Using recursive DP
 * @date 29-05-2023
 * 
 * Runtime - 656 ms
 * Memory Usage - 69.6 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> piles;
  map<pair<int, int>, int> dp;

  int helper(int l, int r) {
    if (l > r) return 0;

    if (dp.find({l, r}) != dp.end()) return dp[{l, r}];

    int ans = INT_MIN;
    ans = max(ans, piles[l] - helper(l + 1, r));

    ans = max(ans, piles[r] - helper(l, r - 1));

    dp[{l, r}] = ans;
    return ans;
  }

  bool stoneGame(vector<int>& piles) {
    int l = 0, r = piles.size() - 1;
    this->piles = piles;

    int alice = helper(0, r);
    return alice > 0;
  }
};