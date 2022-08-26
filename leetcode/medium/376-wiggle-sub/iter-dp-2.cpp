/**
 * @file iter-dp-2.cpp
 * @author Vortexx2
 * @brief Problem 376 - Wiggle Subsequence
 * @approach Using `ups` and `downs` arrays to show the largest subsequence at a
 * particular index considering a positive and negative wiggle as the last
 * wiggle that occurs.
 * @date 25-08-2022
 *
 * Runtime - 17 ms O(n ^ 2)
 * Memory Usage - 7.5 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) return n;

    // longest subsequence that is contained till that index where the last
    // wiggle is a positive wiggle
    vector<int> ups(n, 1);
    // longest subsequence that is contained till that index where the last
    // wiggle is a negative wiggle
    vector<int> downs(n, 1);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // update ups[i] if current number is greater than the iterated number
        // and the sequence after adding current number is greater than current
        // sequence
        if (nums[i] > nums[j]) {
          ups[i] = max(ups[i], downs[j] + 1);
        }
        // update downs[i] if the current number is lesser than the iterated
        // number and the sequence after adding current number has greater
        // length than the current sequence
        else if (nums[i] < nums[j]) {
          downs[i] = max(downs[i], ups[j] + 1);
        }
      }
    }

    // one of ups[n - 1] or downs[n - 1] will have the maximum length possible,
    // since it will keep on getting carried forward to one of the values
    // regardless of
    return max(ups[n - 1], downs[n - 1]);
  }
};