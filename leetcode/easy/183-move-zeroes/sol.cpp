/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 183 - Move Zeroes
 * @approach 2 pointers
 * @date 06-10-2022
 * 
 * Runtime - 43 ms O(n)
 * Memory Usage - 19.3 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int numZeroes = 0, l = 0, r = 0;

    while (r < n) {
      if (!nums[r]) {
        numZeroes++;
      }

      else {
        nums[l] = nums[r];
        l++;
      }
      r++;
    }

    while (numZeroes) {
      nums[l++] = 0;
      numZeroes--;
    }
  }
};