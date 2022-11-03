/**
 * @file prefix.cpp
 * @author Vortexx2
 * @brief Problem 713 - Subarray Product Less Than K
 * @approach Using prefix sum and binary search.
 * @date 03-11-2022
 * 
 * Runtime - 185 ms O(n * log(n))
 * Memory Usage - 66.5 MB O(n)
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int bSearch(vector<double>& prefix, int base, double target) {
    int high = prefix.size();
    int low = base + 1;
    int mid;

    while (low < high) {
      mid = low + (high - low) / 2;

      if (prefix[mid] - prefix[base] >= target - 1e-9)
        high = mid;

      else
        low = mid + 1;
    }

    return low;
  }

  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;

    int n = nums.size();

    double target = log(k);

    vector<double> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + log(nums[i - 1]);
    }

    int ans = 0;
    int j;
    for (int i = 0; i < n; i++) {
      j = bSearch(prefix, i, target);
      ans += (j - i - 1);
    }

    return ans;
  }
};

int main() {
  Solution sol = Solution();

  // vector<int> nums = {10, 5, 2, 6};
  // vector<int> nums = {1, 1, 1};
  // int target = 1;
  // int target = 100;

  vector<int> nums = {10, 3, 3, 7, 2, 9, 7, 4, 7, 2, 8, 6, 5, 1, 5};
  int target = 30;

  cout << sol.numSubarrayProductLessThanK(nums, target) << endl;
}
