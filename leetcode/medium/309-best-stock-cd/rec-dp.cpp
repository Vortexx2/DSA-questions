/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 309 - Best Time to Buy and Sell Stock with Cooldown
 * @date 11-07-2022
 *
 * Runtime - 3 ms -> O(2 * n)
 * Memory Usage - 13.5 MB -> O(2 * n)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  // maps (i, boughtStock) to maxProfit for memoization
  map<pair<int, bool>, int> dp;
  int maxProfit(vector<int>& prices) {
    // we recursively check all paths from index 0, and where we have not bought
    // the stock at the start
    return dfs(prices, 0, false);
  }

  /**
   * @brief Recursive approach where we use the simple concept that -
   * if we have already bought, we can only hold or sell in the current time
   * instant.
   * if we have not bought, we can only hold or buy in the current time
   * instant.
   * if we sell in the current time instant, we'll cooldown in the next
   * time instant for sure.
   *
   * @param prices
   * @param i index in the prices array
   * @param boughtStock whether we already have bought the 1 allowed stock or
   * not
   * @return int
   */
  int dfs(vector<int>& prices, int i, bool boughtStock) {
    if (i >= prices.size()) return 0;

    if (dp.find({i, boughtStock}) != dp.end()) return dp[{i, boughtStock}];

    if (boughtStock) {
      // sell this instant and cooldown for next instant
      int sell = dfs(prices, i + 2, false) + prices[i];
      // cd this instant
      int cd = dfs(prices, i + 1, true);

      dp[{i, boughtStock}] = max(sell, cd);
    }

    else {
      int buy = dfs(prices, i + 1, true) - prices[i];
      int cd = dfs(prices, i + 1, false);
      dp[{i, boughtStock}] = max(buy, cd);
    }

    return dp[{i, boughtStock}];
  }
};
