/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 368 - Largest Divisible Subset
 * @approach Similar to LIS, creating 2 DP arrays, and then jumping in backwards
 * fashion depending on previously found maxLength element.
 * @date 01-01-2023
 *
 * Runtime - 60 ms O(n ^ 2)
 * Memory Usage - 9 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums;

    sort(nums.begin(), nums.end());

    vector<int> maxLengths(n, 1), prevMaxes(n, -1);
    int maxLengthLastIndex = 0, maxLength = 1;

    // makes vectors maxLengths, prevMaxes
    for (int i = 1; i < n; i++) {
      int currMax = 1, prevMax = -1;

      for (int j = i - 1; j >= 0; j--) {
        // if number is divisible
        if (nums[i] % nums[j] == 0) {
          // if length exceeds previous limit
          if (maxLengths[j] + 1 > currMax) {
            currMax = maxLengths[j] + 1;
            prevMax = j;
          }
        }
      }
      maxLengths[i] = currMax;
      prevMaxes[i] = prevMax;

      // if current max length beats previous record
      if (currMax > maxLength) {
        maxLength = currMax;
        maxLengthLastIndex = i;
      }
    }

    vector<int> res(maxLength);

    // iterate through `maxLength` number of elements to append to res
    for (int i = maxLength - 1; i >= 0; i--) {
      res[i] = nums[maxLengthLastIndex];
      maxLengthLastIndex = prevMaxes[maxLengthLastIndex];
    }

    return res;
  }
};