/**
 * @file bin.cpp
 * @author Vortexx2
 * @brief Problem 153 - Find Minimum In Rotated Sorted Array
 * @approach Using binary search
 * @date 23-10-2022
 * 
 * Runtime - 10 ms O(log n)
 * Memory Usage - 10.1 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isLeftPart(vector<int>& nums, int pos) { return nums[0] <= nums[pos]; }

  int findMin(vector<int>& nums) {

    if (nums[nums.size() - 1] >= nums[0]) return nums[0];


    int l = 0, h = nums.size();
    int mid;

    while (l < h) {
      mid = (l + h) / 2;
      if (isLeftPart(nums, mid))
        l = mid + 1;

      else
        h = mid;
    }

    return nums[l];
  }
};