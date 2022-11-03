/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 713 - Subarray Product Less than K
 * @date 03-11-2022
 * 
 * Runtime - TLE
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int numSubs = 0;
    int currProd = 1;

    while (l < nums.size()) {
      r = l;
      currProd = 1;

      while (r < nums.size() && currProd * nums[r] < k) {
        numSubs++;
        currProd *= nums[r];
        r++;
      }

      l++;
    }

    return numSubs;
  }
};
