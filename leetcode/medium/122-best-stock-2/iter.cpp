/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 122 - Best Time to Buy and Sell Stock II
 * @approach An iterative approach using simple mathematical concepts. We should
 * always buy when we know we will encounter a larger number in the future,
 * because making smaller profits adjacent days is the same as holding for
 * future profit. e.g. 1, 3, 5, 6 - buying and selling every adjacent day is
 * same as holding from 1st to last day.
 * @date 10-07-2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int currMin = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > currMin) maxProfit += prices[i] - currMin;

      currMin = prices[i];
    }

    return maxProfit;
  }
};