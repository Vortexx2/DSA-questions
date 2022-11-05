/**
 * @file better-dfs.cpp
 * @author Vortexx2
 * @brief Problem 200 - Number of Islands
 * @date 05-11-2022
 * @approach Using a DFS approach with just modifying the original grid, rather
 * than making a new visited array.
 *
 * Runtime - 89 ms O(m * n)
 * Memory Usage - 17.2 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    int ans = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '0') continue;

        ans++;
        dfs(grid, i, j);
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>>& grid, int row, int col) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
      return;

    if (grid[row][col] == '0') return;

    grid[row][col] = '0';

    vector<pair<int, int>> posPairs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto& pair : posPairs) {
      dfs(grid, row + pair.first, col + pair.second);
    }
  }
};