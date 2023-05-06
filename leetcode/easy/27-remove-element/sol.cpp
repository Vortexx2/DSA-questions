/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 27 - Remove Element
 * @date 06-05-2023
 * 
 * Runtime - 3 ms O(n)
 * Memory Usage - 8.7 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }
    
    return j;
  }
};