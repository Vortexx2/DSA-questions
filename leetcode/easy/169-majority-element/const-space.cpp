/**
 * @file const-space.cpp
 * @author Vortexx2
 * @brief Problem 169 - Majority Element
 * @approach Using linear time and constant space
 * @date 07-05-2023
 * 
 * Runtime - 19 ms O(n)
 * Memory Usage - 19.7 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 1, ele = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (!count) ele = nums[i];

      count += (ele == nums[i]) ? 1 : -1;
    }

    return ele;
  }
};