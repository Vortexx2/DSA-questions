/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 213 - House Robber 2
 * @date 29-06-2022
 *
 * Runtime - 6 ms
 * Memory Usage - 7.9 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // create 2 sequences for both subproblems we need to tackle
  vector<int> dp1, dp2;

  // signifies where we need to end the algorithm
  int end;

  /**
   * @brief Figure out the max robbable value when we start from the 0th element
   * and when we start from the 1st element, and then return the max of the 2
   * values.
   *
   * @param nums
   * @return int
   */
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    int n = nums.size();
    dp1.resize(n);
    fill(dp1.begin(), dp1.end(), -1);

    dp2.resize(n);
    fill(dp2.begin(), dp2.end(), -1);

    end = 1;
    int a = maxPossible(nums, n - 1, dp1);

    end = 0;
    return max(a, maxPossible(nums, n - 2, dp2));
  }

  /**
   * @brief Figures out the max possible robbable amount from current to end
   * specified by the class attribute
   *
   * @param nums
   * @param current
   * @param dp
   * @return int
   */
  int maxPossible(vector<int>& nums, int current, vector<int>& dp) {
    if (current < end) return 0;

    if (dp[current] != -1) return dp[current];

    dp[current] = max(maxPossible(nums, current - 1, dp),
                      maxPossible(nums, current - 2, dp) + nums[current]);
    return dp[current];
  }
};