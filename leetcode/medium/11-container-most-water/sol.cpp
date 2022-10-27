/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 11 - Container With Most Water
 * @approach Using a 2 pointer approach
 * @date 27-10-2022
 * 
 * Runtime - 217 ms O(n)
 * Memory Usage - 59 MB O(1)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxArea = INT_MIN;

    while (l < r) {
      maxArea = max(maxArea, min(height[l], height[r]) * (r - l));

      if (height[l] < height[r])
        l++;

      else
        r--;
    }

    return maxArea;
  }
};