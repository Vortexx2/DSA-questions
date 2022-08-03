/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 64 - Minimum Path Sum
 * @date 03-08-2022
 * 
 * Runtime - 16 ms O(m * n)
 * Memory Usage - 9.7 MB O(n) (n = number of columns)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    auto row = firstRow(grid);

    for (int i = 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (j) row[j] = min(row[j], row[j - 1]);

        row[j] += grid[i][j];
      }
    }

    return row[cols - 1];
  }

  vector<int> firstRow(vector<vector<int>>& grid) {
    vector<int> row(grid[0].size());
    row[0] = grid[0][0];
    for (int i = 1; i < grid[0].size(); i++) {
      row[i] = row[i - 1] + grid[0][i];
    }

    return row;
  }
};