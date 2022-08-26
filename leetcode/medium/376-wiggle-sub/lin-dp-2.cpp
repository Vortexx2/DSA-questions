/**
 * @file lin-dp-2.cpp
 * @author Vortexx2
 * @brief Problem 376 - Wiggle Subsequence
 * @date 26-08-2022
 * 
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.1 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    int down = 1, up = 1;

    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1])
        up = down + 1;

      else if (nums[i] < nums[i - 1])
        down = up + 1;
    }

    return max(up, down);
  }
};