/**
 * @file greedy.cpp
 * @author Vortexx2
 * @brief Problem 376 - Wiggle Subsequence
 * @approach Greedy approach, considering that the largest subsequence that is
 * always possible is going to include only the highest peaks and lowest valleys
 * @date 24-09-2022
 *
 * Runtime - 5 ms
 * Memory Usage - 7.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return 1;
    if (n == 2) return (nums[0] == nums[1] ? 1 : 2);

    // to track the previous included difference
    int prevDiff = nums[1] - nums[0];

    // the final count variable that we will return
    int count = (prevDiff == 0) ? 1 : 2;

    for (int i = 2; i < n; i++) {
      int currDiff = nums[i] - nums[i - 1];

      // doesn't matter if previous diff was 0 as long as current diff is non
      // zero
      if ((currDiff < 0 && prevDiff >= 0) || (currDiff > 0 && prevDiff <= 0)) {
        prevDiff = currDiff;
        count++;
      }
    }

    return count;
  }
};