/**
 * @file greedy.cpp
 * @author Vortexx2
 * @brief Problem 55 - Jump Game
 * @approach Using greedy algorithm
 * @date 01-07-2022
 * 
 * Runtime - 71 ms O(n)
 * Memory Usage - 48.5 MB O(1)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;

    int n = nums.size(), goal = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (i + nums[i] >= goal) goal = i;
    }

    return (!goal);
  }
};