/**
 * @file best-dp.cpp
 * @author Vortexx2
 * @brief Problem 213
 * @date 29-06-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 7.8 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    if (n == 3) return max(nums[0], max(nums[1], nums[2]));

    return max(helper(nums, 0, n - 1), helper(nums, 1, n));
  }

  int helper(vector<int>& nums, int start, int end) {
    int a = nums[start], b = max(nums[start], nums[start + 1]);
    int res;

    for (int i = start + 2; i < end; i++) {
      res = max(a + nums[i], b);
      a = b;
      b = res;
    }
    return res;
  }
};
