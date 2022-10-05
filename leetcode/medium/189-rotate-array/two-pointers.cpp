/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 189 - Rotate Array
 * @approach Using 2 pointers
 * @date 05-10-2022
 *
 * Runtime - 67 ms O(n)
 * Memory Usage - 25.6 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    vector<int> dup = nums;
    int n = nums.size();

    int l = 0, r = k % n;

    while (l < n) {
      nums[r] = dup[l];
      l++;
      r = (r + 1) % n;
    }
  }
};