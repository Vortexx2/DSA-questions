/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 55 - Jump Game
 * @approach Dynamic Programming O(n^2)
 * @date 30-06-2022
 * 
 * Time Limit Exceeded
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  map<int, bool> dp;
  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    if (!nums[0]) return false;

    return helper(nums, 0);
  }

  bool helper(vector<int>& nums, int current) {
    if (current >= nums.size() - 1) return true;

    if (nums[current] == 0) return false;

    auto resIter = dp.find(current);

    if (resIter != dp.end()) return resIter->second;

    for (int i = nums[current]; i > 0; i--) {
      int curRes = helper(nums, current + i);

      if (curRes) {
        dp[current] = true;
        return true;
      }
    }

    dp[current] = false;
    return false;
  }
};