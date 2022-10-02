/**
 * @file better-tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 518 - Coin Change 2
 * @approach This has better space complexity than tab-dp, but the idea is the same
 * @date 02-10-2022
 * 
 * Runtime - 32 ms O(m * n) 
 * Memory Usage - 18.4 MB O(n)
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
    vector<int> prevRow(amount + 1, 0), currRow(amount + 1, 0);

    for (int j = n - 1; j >= 0; j--) {
      for (int subAmount = coins[0]; subAmount <= amount; subAmount++) {
        if (coins[j] == subAmount) currRow[subAmount] = 1;

        if (coins[j] < subAmount) {
          currRow[subAmount] =
              prevRow[subAmount] + currRow[subAmount - coins[j]];
        }
      }

      prevRow = currRow;
      currRow = vector<int>(amount + 1, 0);
    }

    return prevRow[amount];
  }
};

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 5;

  Solution sol = Solution();
  cout << sol.change(amount, coins) << endl;
}
