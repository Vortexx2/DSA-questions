/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 217 - Contains Duplicate
 * @date 26-12-2022
 * 
 * Runtime - 114 ms O(n)
 * Memory Usage - 52.2 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> visited;

    for (int i = 0; i < nums.size(); i++) {
      if (visited.find(nums[i]) != visited.end()) return true;

      visited.insert(nums[i]);
    }

    return false;
  }
};