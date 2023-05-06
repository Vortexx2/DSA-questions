/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 80 - Remove Duplicates in Sorted Array 2
 * @date 07-05-2023
 * 
 * Runtime - 4 ms O(n)
 * Memory Usage - 10.9 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int j = 1, count = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        if (count < 2) {
          count++;
          nums[j++] = nums[i];
        }
      }

      else {
        count = 1;
        nums[j++] = nums[i];
      }
    }

    return j;
  }
};