/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 121 - Best Time to Buy and Sell Stock
 * @approach Simple iterative DP approach where minimum price we have
 * encountered up to the current index is memoized.
 * @date 09-07-2022
 *
 * Runtime - 198 ms
 * Memory Usage - 93.3 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];  // min price we have encountered up until now
    int maxProfit = 0;         // max profit up until now
    for (int i = 1; i < prices.size(); i++) {
      maxProfit = max(maxProfit, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
  }
};