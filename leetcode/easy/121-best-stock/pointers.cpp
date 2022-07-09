/**
 * @file pointers.cpp
 * @author Vortexx2
 * @brief Problem 121 - Best Time to Buy and Sell Stock
 * @approach Using 2 pointers for O(n) solution
 * @date 10-07-2022
 * 
 * Runtime - 187 ms
 * Memory Usage - 93.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // left and right pointer
    int left = 0, right = 1;
    int maxProfit = 0;

    while (right < prices.size()) {
      // if left price is lesser than right price, meaning profit is positive
      if (prices[left] < prices[right]) {
        // since profit is positive, this profit can be max profit
        maxProfit = max(maxProfit, prices[right] - prices[left]);
      }
      // right price is lesser than left price, meaning loss
      // meaning a lesser number has been reached
      else {
        left = right;
      }

      right++;
    }

    return maxProfit;
  }
};