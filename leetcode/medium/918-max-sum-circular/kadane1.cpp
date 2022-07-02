/**
 * @file kadane.cpp
 * @author Vortexx2
 * @brief Problem 918 - Max Sum Circular Subarray
 * @approach https://www.youtube.com/watch?v=Q1TYVUEr-wY
 * @date 02-07-2022
 *
 * Runtime - 97 ms
 * Memory Usage - 39.8 MB
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @brief Finds the maximum contiguous subarray sum in a circular array. Takes
   * 2 cases - 1. where the answer exists in 1 interval in nums, 2. where the
   * answer exists in 2 intervals in nums i.e. it is disjoint and wraps around.
   * Returns the max of these 2 cases.
   *
   * @param nums
   * @return int
   */
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int inverted = invertedLargest(nums);

    // for special case where all numbers in nums is negative
    if (inverted == INT_MIN) return kadaneLargest(nums);
    return max(kadaneLargest(nums), invertedLargest(nums));
  }

  /**
   * @brief Finds the largest sum of contiguous subarray in the normal array
   * (not circular). This is the case where the subarray might exist as only 1
   * interval in the middle of the array, and is not disjoint.
   *
   * @param nums
   * @return int
   */
  int kadaneLargest(vector<int>& nums) {
    int maxSum, currSum;
    maxSum = currSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      currSum = max(nums[i] + currSum, nums[i]);

      maxSum = max(currSum, maxSum);
    }

    return maxSum;
  }

  /**
   * @brief Finds the largest 2 interval subarray sum, by finding the sum of the
   * whole array and subtracting the smallest subarray sum.
   *
   * @param nums
   * @return int
   */
  int invertedLargest(vector<int>& nums) {
    int seqSum = nums[0];
    int maxSum, currSum;
    maxSum = currSum = -nums[0];

    for (int i = 1; i < nums.size(); i++) {
      currSum = max(currSum - nums[i], -nums[i]);
      maxSum = max(currSum, maxSum);
      seqSum += nums[i];
    }

    // special case where all numbers in nums are negative
    if (maxSum + seqSum == 0) return INT_MIN;

    return seqSum + maxSum;
  }
};
