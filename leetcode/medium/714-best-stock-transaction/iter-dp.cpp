/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 714 - Best Time to Buy and Sell Stock with Txn. Fees
 * @approach Using an iterative approach we keep track of the max profit today
 * if we held stock or did not hold any stock
 * @date 12-07-2022
 *
 * Runtime - 176 ms O(n)
 * Memory Usage - 55 MB O(1)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int cash = 0,  // max profit we could have if we didn't have a share of
                   // stock at the current time step
        hold = -prices[0];  // max profit we could have if we had a share of
                            // stock at the current time step

    for (int i = 1; i < prices.size(); i++) {
      // at current time step

      // max cash in hand without any stock occurs if -
      // we don't buy any stock today or
      // we sell stock that we held on till yesterday and pay the fee
      cash = max(cash, hold + prices[i] - fee);

      // similar logic applies to this as well
      hold = max(hold, cash - prices[i]);
    }

    return cash;
  }
};