/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1470 - Shuffle the array
 * @date 06-02-2023
 * 
 * Runtime - 3 ms O(n)
 * Memory Usage - 9.7 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2 * n);

    int l = 0, r = n;
    int i = 0;

    while (i < res.size()) {
      res[i++] = nums[l];
      res[i++] = nums[r];
      l++, r++;
    }

    return res;
  }
};