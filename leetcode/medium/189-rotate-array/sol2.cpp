/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 189 - Rotate Array
 * @approach Using reversal of array
 * @date 05-10-2022
 * 
 * Runtime - 43 ms O(N)
 * Memory Usage - 25 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k = k % n;

    if (!k) return;

    reverseArray(nums, 0, n - 1);
    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
  }

  void reverseArray(vector<int>& nums, int start, int end) {
    while (start <= end) {
      swap(nums[start], nums[end]);
      start++;
      end--;
    }
  }
};