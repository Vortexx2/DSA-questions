/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 343 - Integer Break
 * @date 03-10-2022
 *
 * Runtime - 3 ms O(n ^ 2)
 * Memory Usage - 6.3 MB O(n)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 2) return 1;
    vector<int> dp(n + 1, 1);

    for (int i = 3; i <= n; i++) {
      int maxProd = INT_MIN;

      for (int j = i - 1; j >= 2; j--) {
        maxProd = max(maxProd, max(j * (i - j), dp[j] * (i - j)));
      }

      dp[i] = maxProd;
    }

    return dp[n];
  }
};