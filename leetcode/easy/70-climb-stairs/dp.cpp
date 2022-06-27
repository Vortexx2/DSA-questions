/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 70
 * @date 27-06-2022
 *
 * Runtime - 4 ms
 * Memory Usage - 6.4 MB
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dp = {0, 1, 2, 3};
  int climbStairs(int n) {
    if (n <= 3) return n;

    return helper(n);
  }

  int helper(int n) {
    if (n < dp.size()) return dp[n];

    dp.push_back(helper(n - 1) + helper(n - 2));
    return dp[n];
  }
};