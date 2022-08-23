/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 376 - Wiggle Subsequence
 * @approach Iterative DP 1D solution
 * @date 23-08-2022
 * 
 * Runtime - 25 ms O(n ^ 2)
 * Memory Usage - 7.2 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) {
      return 1;
    }

    int maxLength = 1;

    // `wiggleLengths[i]` represents the maximum wiggle length ending at i
    // including position i
    vector<int> wiggleLengths(n, 1);
    vector<int> diffs(n, 1);
    diffs[0] = nums[0] - nums[1];

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // if both numbers are equal they will not alternate
        if (nums[i] == nums[j]) {
          wiggleLengths[i] = 0;
        }

        // both numbers are not equal
        else {
          if (j == 0) {
            wiggleLengths[i] = 2;
            diffs[i] = nums[i] - nums[j];
          }

          else {
            if (
                // if alternative positive and negative
                (nums[i] - nums[j]) * diffs[j] < 0 &&
                // if current length is lesser than equal to the jth length
                (wiggleLengths[i] <= wiggleLengths[j])) {

              // increment by adding current number to subsequence
              wiggleLengths[i] = 1 + wiggleLengths[j];
              diffs[i] = nums[i] - nums[j];
            }
          }
        }
      }

      maxLength = max(maxLength, wiggleLengths[i]);
    }

    return maxLength;
  }
};