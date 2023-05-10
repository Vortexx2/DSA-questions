/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 31 - Next Permutation
 * @approach https://www.youtube.com/watch?v=LuLCLgMElus
 * @date 10-05-2023
 * 
 * Runtime - 4 ms O(n)
 * Memory Usage - 11.9 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return;

    int i1 = n - 2;
    while (i1 >= 0 && nums[i1] >= nums[i1 + 1]) i1--;

    if (i1 != -1) {
      int i2 = n - 1;
      while (i2 > i1 && nums[i1] >= nums[i2]) i2--;

      swap(nums[i1], nums[i2]);
    }

    reverse(nums.begin() + i1 + 1, nums.end());
  }
};