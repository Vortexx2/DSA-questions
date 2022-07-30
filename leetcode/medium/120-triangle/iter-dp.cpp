/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 120 - Triangle
 * @approach Using an iterative DP approach. We don't need to track more than
 * the previous row to be able to calculate the optimum path.
 * @date 30-07-2022
 *
 * Runtime - 4 ms
 * Memory Usage - 8.9 MB
 */
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int height = triangle.size();

    if (height == 1) {
      return triangle[0][0];
    }

    // maps the best path for each respective index in the previous row
    vector<int> prevRowDP = triangle[height - 1];

    for (int row = height - 2; row >= 0; row--) {
      // tracks current row least costs according to their index
      vector<int> currDP(triangle[row].size());

      for (int col = 0; col < triangle[row].size(); col++) {
        currDP[col] =
            triangle[row][col] + min(prevRowDP[col], prevRowDP[col + 1]);
      }

      prevRowDP = currDP;
    }

    return prevRowDP[0];
  }
};
