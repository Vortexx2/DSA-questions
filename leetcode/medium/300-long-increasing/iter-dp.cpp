/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 300 - Longest Increasing Subsequence
 * @approach Iterative DP 1D memoization approach
 * @date 22-08-2022
 * 
 * Runtime - 387 ms O(n ^ 2)
 * Memory Usage - 10.6 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    // each position gives us the value of the longest subsequence ending at
    // that position, including that position
    vector<int> increasingSub(n, 1);

    int maxSubLength = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && increasingSub[i] <= increasingSub[j]) {
          increasingSub[i] = 1 + increasingSub[j];
        }
      }

      maxSubLength = max(maxSubLength, increasingSub[i]);
    }

    return maxSubLength;
  }
};