/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 377 - Combination Sum 4
 * @approach Recursive top down approach with memoization
 * @date 02-10-2022
 *
 * Runtime - 9 ms O(nums * target)
 * Memory Usage - 7 MB O(nums * target)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<int, int> dp;  // maps target to amount of ways possible

  int combinationSum4(vector<int>& nums, int target) {
    if (!target) return 1;

    return helper(nums, target);
  }

  int helper(vector<int>& nums, int target) {
    if (dp.find(target) != dp.end()) return dp[target];

    int ways = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) ways += 1;

      if (nums[i] < target) ways += helper(nums, target - nums[i]);
    }

    dp[target] = ways;
    return ways;
  }
};