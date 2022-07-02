/**
 * @file kadane2.cpp
 * @author Vortexx2
 * @brief Problem 918 - Max Sum Circular Subarray
 * @approach Using leetcode's registered solution number 1.
 * @date 02-07-2022
 * 
 * Runtime - 94 ms
 * Memory Usage - 41.5 MB
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int kadane = kadaneLargest(nums);

    return max(kadane, max2IntervalSum(nums));
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
   * @brief Finds the largest possible 2 interval sum i.e. max sum for intervals
   * (0, i), (j, len(nums) - 1), where j >= (i + 2).
   * Let T_j = A[j] + A[j + 1] + ... + A[len - 1].
   * R_j = max(T_k) for k >= j.
   * Y_i = (A[0] + A[1] + ... + A[i]) + R_(i + 2).
   * 
   * Therefore, we need max(Y_i).
   *
   * @param nums
   * @return int
   */
  int max2IntervalSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> rights(n, 0);
    rights[n - 1] = nums[n - 1];
    int currSum = nums[n - 1];

    // greatest sum possible till the current index from the right when we
    // include the rightmost element
    for (int i = n - 2; i >= 2; i++) {
      currSum += nums[i];
      rights[i] = max(currSum, rights[i + 1]);
    }

    currSum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n - 2; i++) {
      currSum += nums[i];
      ans = max(ans, currSum + rights[i + 2]);
    }

    return ans;
  }
};
