/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 279 - Perfect Squares
 * @approach Using a coin change approach using bottom up tabulation
 * @date 03-10-2022
 * 
 * Runtime - O(n ^ 3 /2)
 * Memory Usage - O(n)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> coins;

    // add all squares to an array
    int i = 1;
    int squareValue = 1;
    while (squareValue <= n) {
      if (squareValue == n) return 1;

      coins.push_back(squareValue);
      i++;
      squareValue = i * i;
    }

    // all of the below code is similar to Coin Change
    int len = coins.size();
    vector<int> prevRow(n + 1, n + 1), currRow(n + 1, n + 1);

    for (int j = len - 1; j >= 0; j--) {
      for (int subAmount = 0; subAmount <= n; subAmount++) {
        if (coins[j] == subAmount) currRow[subAmount] = 1;

        if (coins[j] < subAmount)
          currRow[subAmount] =
              min(currRow[subAmount - coins[j]] + 1, prevRow[subAmount]);
      }

      prevRow = currRow;
      currRow = vector<int>(n + 1, n + 1);
    }

    return prevRow[n];
  }
};