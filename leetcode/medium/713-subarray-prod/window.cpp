/**
 * @file window.cpp
 * @author Vortexx2
 * @brief Problem 713 - Subarray Product Less Than K
 * @approach Using a sliding window appraoch
 * @date 04-11-2022
 * 
 * Runtime - 83 ms O(n)
 * Memory Usage - 61.2 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans = 0, prod = 1, l = 0;

    for (int r = 0; r < nums.size(); r++) {
      prod *= nums[r];
      while (l <= r && prod >= k) prod /= nums[l++];

      printf("l, r: %d, %d\n", l, r);

      ans += r - l + 1;
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();

  vector<int> nums = {10, 5, 2, 6};
  int target = 100;

  cout << sol.numSubarrayProductLessThanK(nums, target) << endl;
}
