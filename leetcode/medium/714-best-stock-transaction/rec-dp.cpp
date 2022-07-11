/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 714 - Best Time to Buy and Sell Stock with Txn. Fees
 * @approach Recursive memoization approach with states for each scenario.
 * @date 11-07-2022
 * 
 * Runtime - 1768 ms
 * Memory Usage - 155 MB
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<pair<int, bool>, int> dp;  // maps (i, hasStock) to maxProfit
  int trFee;
  int maxProfit(vector<int>& prices, int fee) {
    trFee = fee;

    return dfs(prices, 0, false);
  }

  int dfs(vector<int>& prices, int i, bool hasStock) {
    if (i >= prices.size()) return 0;

    if (dp.find({i, hasStock}) != dp.end()) return dp[{i, hasStock}];

    if (hasStock) {
      int sell = dfs(prices, i + 1, false) + prices[i] - trFee;
      int cd = dfs(prices, i + 1, true);
      dp[{i, hasStock}] = max(sell, cd);
    }

    else {
      int buy = dfs(prices, i + 1, true) - prices[i];
      int cd = dfs(prices, i + 1, false);
      dp[{i, hasStock}] = max(buy, cd);
    }

    return dp[{i, hasStock}];
  }
};