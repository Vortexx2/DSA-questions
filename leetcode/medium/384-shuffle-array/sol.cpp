/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 384 - Shuffle an Array
 * @date 24-12-2022
 * 
 * Runtime - 55 ms
 * Memory Usage - 57.1 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> numbers;
  vector<int> re;
  Solution(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
      numbers.push_back(nums[i]);
      re.push_back(nums[i]);
    }
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return re; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = 0; i < numbers.size(); i++) {
      int temp = rand() % numbers.size();
      int l = numbers[i];
      numbers[i] = numbers[temp];
      numbers[temp] = l;
    }
    return numbers;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */