/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 322 - Coin Change
 * @approach Top down DP appraoch which is naive
 * @date 24-09-2022
 * 
 * Runtime - 1526 ms
 * Memory Usage - 71 MB
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<int, int> dp;  // maps amount to if it is solvable or not
  int coinChange(vector<int>& coins, int amount) {
    if (!amount) return 0;

    int minCoins = helper(coins, amount);

    if (minCoins == INT_MAX) {
      return -1;
    }

    return minCoins;
  }

  int helper(vector<int>& coins, int amount) {
    if (dp.find(amount) != dp.end()) return dp[amount];

    int minCoins = INT_MAX;

    for (int i = 0; i < coins.size(); i++) {
      if (coins[i] == amount) {
        minCoins = 1;
        break;
      }

      if (coins[i] < amount) {
        int help = helper(coins, amount - coins[i]);

        if (help != INT_MAX) minCoins = min(minCoins, help + 1);
      }
    }

    dp[amount] = minCoins;

    return minCoins;
  }
};

int main() {
  vector<int> coins = {186, 419, 83, 408};
  int amount = 6249;
  // int amount = 3;
  // vector<int> coins = {2};

  Solution sol = Solution();

  cout << sol.coinChange(coins, amount) << endl;
}