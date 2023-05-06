/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 80 - Remove Duplicates From Sorted Array 2
 * @date 07-05-2023
 * 
 * Runtime - 0 ms O(n)
 * Memory Usage - 11.2 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int j = 2;
    vector<pair<int, int>> t;

    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1] || nums[i] != nums[i - 2])
        t.push_back({j++, nums[i]});
    }

    for (auto& p : t) nums[p.first] = p.second;

    return j;
  }
};