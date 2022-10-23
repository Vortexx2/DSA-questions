/**
 * @file bin.cpp
 * @author Vortexx2
 * @brief Problem 162 - Find Peak Element
 * @approach Using binary search. We know that hte peak element will be at the
 * end of an increasing subarray. Therefore, binary search can thought of as
 * being applied to that subarray.
 * @date 23-10-2022
 *
 * Runtime - 4 ms O(log n)
 * Memory Usage - 8.8 MB O(1)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0, h = nums.size(), mid;

    nums.push_back(INT_MIN);

    while (l < h) {
      mid = (l + h) / 2;

      if (nums[mid] < nums[mid + 1]) {
        l = mid + 1;
      }

      else {
        h = mid;
      }
    }

    return l;
  }
};