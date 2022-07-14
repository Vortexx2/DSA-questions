/**
 * @file two-pointers.cpp
 * @author Vortexx2
 * @brief Problem 413 - Arithmetic Slices
 * @approach Using a sliding window technique to see which windows have valid
 * arithmetic sequences.
 * @date 14-07-2022
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.1 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) return 0;

    int ans = 0,           // answer that we will return
        currPossible = 0;  // the number of possible subarrays for the current
                           // sliding window

    // start and end of window
    int windowStart = 0, windowEnd = 2;
    int firstDiff, secondDiff = nums[1] - nums[0];

    while (windowEnd < n) {
      firstDiff = secondDiff;
      secondDiff = nums[windowEnd] - nums[windowEnd - 1];

      // arithmetic sequence continues
      if (secondDiff == firstDiff) {
        currPossible = numPossibleSubarrays(windowEnd - windowStart + 1);
        windowEnd++;
      }

      // current arithmetic sequence has ended
      else {
        windowStart = windowEnd - 1;
        windowEnd++;
        ans += currPossible;
        currPossible = 0;
      }
    }

    ans += currPossible;
    return ans;
  }

  /**
   * @brief Calculates the number of possible contiguous subarrays given the
   * length.
   *
   * @param len Length of original array
   * @return int
   */
  int numPossibleSubarrays(int len) { return ((len - 2) * (len - 1)) / 2; }
};