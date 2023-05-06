/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 26 - Remove Duplicates From Sorted Array
 * @date 06-05-2023
 * 
 * Runtime - 15 ms O(n) 
 * Memory Usage - 18.3 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) return 1;

    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] != nums[i]) nums[j++] = nums[i];
    }

    return j;
  }
};