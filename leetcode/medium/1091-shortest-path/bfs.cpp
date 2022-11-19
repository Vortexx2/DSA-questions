/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1091 - Shortest Path in Binary Matrix
 * @date 19-11-2022
 * 
 * Runtime - 961 ms O(n ^ 2)
 * Memory Usage - 171.7 MB O(n ^ 2)
 */
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    if (grid[0][0] || grid[n - 1][n - 1]) return -1;

    // stores row, col, length to get there
    queue<vector<int>> q;
    q.push({0, 0, 1});

    vector<pair<int, int>> dir = {{1, 1},  {1, 0},  {0, 1},  {1, -1},
                                  {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

    while (!q.empty()) {
      vector<int> temp = q.front();
      q.pop();
      int cRow = temp[0], cCol = temp[1], cScore = temp[2];

      if (cRow < 0 || cCol < 0 || cRow >= n || cCol >= n) continue;

      if (grid[cRow][cCol]) continue;

      if (cRow == n - 1 && cCol == n - 1) return cScore;

      for (auto& d : dir) {
        q.push({cRow + d.first, cCol + d.second, cScore + 1});
      }

      grid[cRow][cCol] = 1;
    }

    return -1;
  }
};