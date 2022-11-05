/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 200 - Number of Islands
 * @approach Using a DFS approach
 * @date 05-11-2022
 *
 * Runtime - 85 ms O(m * n) 
 * Memory Usage - 17.5 MB O(m * n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int res = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // if water or visited already
        if (grid[i][j] == '0' || visited[i][j]) continue;

        // if land and not visited
        res++;
        dfs(grid, visited, i, j);
      }
    }

    return res;
  }

  void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row,
           int col) {
    if (row == -1 || row == grid.size() || col == -1 || col == grid[0].size())
      return;

    if (grid[row][col] == '0' || visited[row][col]) return;

    visited[row][col] = true;

    vector<pair<int, int>> posPairs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto& p : posPairs) {
      dfs(grid, visited, row + p.first, col + p.second);
    }
  }
};