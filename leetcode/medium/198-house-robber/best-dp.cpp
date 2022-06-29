/**
 * @file best-dp.cpp
 * @author Vortexx2
 * @brief Problem 198
 * @date 29-06-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 7.6 MB
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    int a = nums[0], b = max(nums[0], nums[1]);
    int res;

    for (int i = 2; i < n; i++) {
      res = max(a + nums[i], b);
      a = b;
      b = res;
    }

    return res;
  }
};