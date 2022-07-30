/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 120 - Triangle
 * @approach Recursive DP 
 * @date 30-07-2022
 * 
 * Runtime - 29 ms
 * Memory Usage - 12.2 MB
 */
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<pair<int, int>, int> dp;

  int minimumTotal(vector<vector<int>>& triangle) {
    return helper(triangle, 0, 0);
  }

  int helper(vector<vector<int>>& triangle, int row, int col) {
    if (col == -1) return INT_MAX;

    if (col == triangle[row].size()) return INT_MAX;

    if (row == triangle.size() - 1) return triangle[row][col];

    if (dp.find({row, col}) != dp.end()) return dp[{row, col}];

    dp[{row, col}] =
        triangle[row][col] +
        min(helper(triangle, row + 1, col), helper(triangle, row + 1, col + 1));

    return dp[{row, col}];
  }
};