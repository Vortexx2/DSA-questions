/**
 * @file bottom-up-dp.cpp
 * @author Vortexx2
 * @brief Problem 322 - Coin change
 * Approach - Iterative DP approach
 * @date 27-09-2022
 *
 * Runtime - 86 ms
 * Memory Usage - 14.4 MB
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (!amount) return 0;

    // sorting will help us out to pre-stop the iterations
    sort(coins.begin(), coins.end());

    // no coins can be used for this amount
    if (coins[0] > amount) return -1;

    int n = coins.size();

    // stores minimum coins required for each amount
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    // all amounts lesser than the smallest value will have minimum coins
    // required -1 (since its not possible)
    for (int i = coins[0]; i <= amount; i++) {
      for (const int coin : coins) {
        if (coin == i) {
          dp[i] = 1;
          break;
        }

        if (coin < i) {
          int diff = i - coin;

          if (dp[diff] != INT_MAX) dp[i] = min(dp[i], dp[diff] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main() {
  Solution sol = Solution();
  vector<int> arr = {186, 419, 83, 408};
  int target = 6249;

  cout << sol.coinChange(arr, target) << endl;
}