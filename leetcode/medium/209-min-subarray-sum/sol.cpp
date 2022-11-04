/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 209 - Minimum Size Subarray Sum 
 * @approach Using a sliding window approach
 * @date 04-11-2022
 * 
 * Runtime - 62 ms O(n)
 * Memory Usage - 28.1 MB O(1)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0;
    int currSum = nums[0];
    int minLength = INT_MAX;

    while (l < nums.size() && r < nums.size()) {
      if (nums[l] >= target) return 1;

      if (currSum >= target) {
        minLength = min(minLength, r - l + 1);
        currSum -= nums[l];
        l++;
      }

      else {
        if (r >= nums.size() - 1) break;

        r++;
        currSum += nums[r];
      }
    }

    if (minLength == INT_MAX) return 0;

    return minLength;
  }
};