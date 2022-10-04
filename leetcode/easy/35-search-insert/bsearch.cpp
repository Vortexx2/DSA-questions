/**
 * @file bsearch.cpp
 * @author Vortexx2
 * @brief Problem 35 - Search Insert Position
 * @approach Using binary search
 * @date 04-10-2022
 *
 * Runtime - 8 ms O(logn)
 * Memory Usage - 9.8 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid = (low + high) / 2;

    while (low < high) {
      if (nums[mid] == target)
        return mid;

      else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid;

      mid = (low + high) / 2;
    }

    return mid;
  }
};