/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 704 - Binary Search
 * @date 04-10-2022
 * 
 * Runtime - 87 ms O(logn)
 * Memory Usage - 27.5 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    int mid;

    while (low < high) {
      mid = (low + high) / 2;

      if (nums[mid] == target)
        return mid;

      else if (nums[mid] < target)
        low = mid + 1;

      else
        high = mid;
    }

    return -1;
  }
};