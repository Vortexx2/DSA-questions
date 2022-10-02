/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 518 - Coin Change 2
 * @approach Bottom up tabulation dp approach
 * @date 02-10-2022
 * 
 * Runtime - 72 ms O(m * n)
 * Memory Usage - 18.4 MB O(m * n)
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    if (!amount) return 1;

    sort(coins.begin(), coins.end());

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int subAmount = coins[0]; subAmount <= amount; subAmount++) {
      for (int j = n - 1; j >= 0; j--) {
        if (coins[j] == subAmount) dp[j][subAmount] = 1;

        if (coins[j] < subAmount)
          dp[j][subAmount] = dp[j][subAmount - coins[j]] + dp[j + 1][subAmount];
      }
    }

    return dp[0][amount];
  }
};
