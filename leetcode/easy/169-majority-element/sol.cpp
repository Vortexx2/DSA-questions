/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 169 - Majority Element
 * @approach Using linear time and space
 * @date 07-05-2023
 * 
 * Runtime - 25 ms O(n)
 * Memory Usage - 19.5 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> counter;

    for (int i = 0; i < nums.size(); i++) {
      counter[nums[i]]++;
    }

    int element, maxCount = 0;
    for (auto it = counter.begin(); it != counter.end(); it++) {
      if (it->second >= maxCount) {
        element = it->first;
        maxCount = it->second;
      }
    }
    return element;
  }
};