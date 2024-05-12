/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2373 - Largest Local Values in a Matrix
 * @date 12-05-2024
 * 
 * Runtime - 6 ms O(n ^ 4)
 * Memory Usage - 13.52 MB O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));

    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        int maxValue = INT_MIN;
        for (int x = i - 1; x <= i + 1; x++) {
          for (int y = j - 1; y <= j + 1; y++) {
            maxValue = max(maxValue, grid[x][y]);
          }
        }

        res[i - 1][j - 1] = maxValue;
      }
    }

    return res;
  }
};