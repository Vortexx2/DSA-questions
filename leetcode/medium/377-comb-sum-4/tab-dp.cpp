/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 377 - Combination Sum 4
 * @approach Bottom up DP tabulation approach
 * @date 02-10-2022
 * 
 * Runtime - 5 ms O(nums * target)
 * Memory Usage - 6.6 MB O(target)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    if (!target) return 1;

    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int subTarget = 1; subTarget <= target; subTarget++) {
      int ways = 0;
      for (const int& num : nums) {
        if (num == subTarget) ways += 1;

        if (num < subTarget) ways += dp[subTarget - num];
      }

      dp[subTarget] = ways;
    }

    return dp[target];
  }
};