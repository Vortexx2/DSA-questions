/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 198 - House Robber
 * @approach Iterative DP approach (https://www.youtube.com/watch?v=73r3KWiEvyk)
 * @date 28-06-2022
 *
 * Runtime - 0 ms
 * Memory Usage - 7.8 MB
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int len = nums.size();

    // return the value of the only house that can be robbed
    if (len == 1) return nums[0];

    // a vector that represents the max possible value of robbing the houses up
    // to and including that index. Represents the solution to the subproblem.
    vector<int> dp(len, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < len; i++) {
      // current max possible value is either:
      // 1. max value 2 positions ago + nums[i]
      // 2. max value 1 position ago (which means max value till 1 position ago)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[len - 1];
  }
};