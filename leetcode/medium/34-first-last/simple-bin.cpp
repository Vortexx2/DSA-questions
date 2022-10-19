/**
 * @file simpel-bin.cpp
 * @author Vortexx2
 * @brief Problem 34 - First and Last Position of Element in Sorted Array
 * @date 19-10-2022
 * 
 * Runtime - 7 ms O(logn + n)
 * Memory Usage - 13.7 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int binSearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    int mid;

    while (low < high) {
      mid = (low + high) / 2;

      if (nums[mid] == target) return mid;

      if (nums[mid] < target) low = mid + 1;

      if (nums[mid] > target) high = mid;
    }

    return -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    if (!nums.size()) return {-1, -1};

    int search = binSearch(nums, target);

    if (search == -1) return {-1, -1};

    int l = search, r = search;
    while (l >= 0 && nums[l] == target) l--;

    while (r < nums.size() && nums[r] == target) r++;

    return {l + 1, r - 1};
  }
};