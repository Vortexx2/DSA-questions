/**
 * @file xor.cpp
 * @author Vortexx2
 * @brief Problem 136 - Single Number
 * @approach Using xor to keep track if the numbers balance out or not
 * @date 17-10-2022
 * 
 * Runtime - 18 ms O(n)
 * Memory Usage - 17 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int xorVal = 0;

    for (auto& num : nums) {
      xorVal = xorVal ^ num;
    }
    return xorVal;
  }
};