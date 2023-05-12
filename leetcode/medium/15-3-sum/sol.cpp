/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 15 - 3 Sum
 * @approach Sort the original array, choose the first element and use 2 sum on the remaining elements.
 * @date 25-10-2022
 * 
 * Runtime - 158 ms O(n ^ 2)
 * Memory Usage - 20 MB O(1)
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // sort the original array
    sort(nums.begin(), nums.end());

    int n = nums.size();

    vector<vector<int>> res;

    // fix one element and perform 2 Sum on the remaining elements
    for (int first = 0; first < n - 2; first++) {
      // all of the valid combinations have been explored already
      if (first > 0 && nums[first] == nums[first - 1]) continue;

      // if first num is positive, impossible to sum to 0
      if (nums[first] >= 0) break;

      int target = -nums[first];

      int l = first + 1, r = n - 1;
      while (l < r) {
        if (l > first + 1 && nums[l] == nums[l - 1]) {
          l++;
          continue;
        }

        if (r < n - 1 && nums[r] == nums[r + 1]) {
          r--;
          continue;
        }

        int sum = nums[l] + nums[r];

        if (sum == target) {
          res.push_back({nums[first], nums[l], nums[r]});
          l++;
          r--;
        }

        else if (sum < target)
          l++;

        else
          r--;
      }
    }

    return res;
  }
};