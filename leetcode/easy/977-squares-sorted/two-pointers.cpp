/**
 * @file two-pointers.cpp
 * @author Vortexx2
 * @brief Problem 977 - Squares of a Sorted Array
 * @approach - Two pointers
 * @date 05-10-2022
 *
 * Runtime - 65 ms O(n)
 * Memory Usage - 25.9 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);

    int l = 0, r = n - 1;
    int k = n - 1;

    while (l <= r) {
      if (abs(nums[l]) > abs(nums[r])) {
        res[k] = nums[l] * nums[l];
        l++;
      }

      else {
        res[k] = nums[r] * nums[r];
        r--;
      }

      k--;
    }

    return res;
  }
};