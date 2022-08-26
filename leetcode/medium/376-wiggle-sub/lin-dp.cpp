/**
 * @file lin-dp.cpp
 * @author Vortexx2
 * @brief Problem 376 - Wiggle Subsequence
 * @approach Using a linear DP approach
 * @date 26-08-2022
 * 
 * Runtime - 5 ms O(n)
 * Memory Usage - 7.3 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) return nums.size();

    // a particular element shows the longest subsequence with a positive wiggle
    // as the last wiggle
    vector<int> ups(n, 1);
    // a particular element shows the longest subsequence with a negative wiggle
    // as the last wiggle
    vector<int> downs(n, 1);

    for (int i = 1; i < n; i++) {

      // if current nums is greater than previous num, that means it's a positive wiggle
      if (nums[i] > nums[i - 1]) {
        // increase the downs before the subsequence by 1
        ups[i] = downs[i - 1] + 1;
        downs[i] = downs[i - 1];
      }

      else if (nums[i] < nums[i - 1]) {
        // increase the ups before the subsequence by 1
        ups[i] = ups[i - 1];
        downs[i] = ups[i - 1] + 1;
      }

      else {
        ups[i] = ups[i - 1];
        downs[i] = downs[i - 1];
      }
    }

    return max(ups[n - 1], downs[n - 1]);
  }
};