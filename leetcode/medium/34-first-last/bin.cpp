/**
 * @file bin.cpp
 * @author Vortexx2
 * @brief Problem 34 - Find First and Last Position of Element in Sorted Array
 * @approach Using 2 binary searches
 * @date 19-10-2022
 * 
 * Runtime - 13 ms O(logn)
 * Memory Usage - 13.7 MB O(1) 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (!nums.size() || target < nums[0] || target > nums[nums.size() - 1])
      return {-1, -1};

    if (nums.size() == 1 && nums[0] == target) return {0, 0};

    return {binSearch(nums, target, true), binSearch(nums, target, false)};
  }

  int binSearch(vector<int>& nums, int target, bool searchLeft) {
    int l = 0, h = nums.size();
    int prev = -1;
    int mid;

    while (l <= h) {
      mid = (l + h) / 2;

      if (mid >= nums.size()) return prev;

      if (nums[mid] == target) {
        prev = mid;
        if (searchLeft)
          h = mid - 1;
        else
          l = mid + 1;
      }

      else if (nums[mid] < target)
        l = mid + 1;

      else
        h = mid - 1;
    }

    return prev;
  }
};