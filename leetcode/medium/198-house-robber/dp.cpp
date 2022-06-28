/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 198 - House Robber
 * @date 28-06-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 7.9 MB
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dp;
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    dp.resize(nums.size());
    fill(dp.begin(), dp.end(), -1);

    return max(helper(nums, 0), helper(nums, 1));
  }

  int helper(vector<int>& nums, int current) {
    if (current >= nums.size()) return 0;

    if (dp[current] != -1) return dp[current];

    dp[current] = max(helper(nums, current + 2), helper(nums, current + 3)) +
                  nums[current];

    return dp[current];
  }
};