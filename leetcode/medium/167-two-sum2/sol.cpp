/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 167 - Two Sum 2
 * @approach Using 2 pointer approach
 * @date 06-10-2022
 * 
 * Runtime - 26 ms O(n)
 * Memory Usage - 15.7 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int l = 0, r = n - 1;

    while (l < r) {
      if (numbers[l] + numbers[r] == target)
        return {l + 1, r + 1};

      else if (numbers[l] + numbers[r] > target) {
        r--;
      } else {
        l++;
      }
    }

    return {};
  }
};