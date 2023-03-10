/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1162 - As Far From Land As Possible
 * @date 10-03-2023
 * 
 * Runtime - 605 ms
 * Memory Usage - 109.5 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  // dimensions of the grid
  int n;

  int validPos(int row, int col) {
    return (row < 0 || row >= n || col < 0 || col >= n);
  }

  int bfs(vector<vector<int>>& grid, queue<vector<int>>& q) {
    if (q.empty() || q.size() == n * n) return -1;

    vector<vector<int>> distGrid(n, vector<int>(n, -1));

    int maxDist = -1;

    while (!q.empty()) {
      int row = q.front()[0], col = q.front()[1], dist = q.front()[2];
      q.pop();

      if (validPos(row, col)) continue;

      // if we have encountered this water cell before
      if (distGrid[row][col] != -1) continue;

      distGrid[row][col] = dist;
      maxDist = max(maxDist, dist);
      for (auto& d : dirs) q.push({row + d.first, col + d.second, dist + 1});
    }

    return maxDist;
  }

  int maxDistance(vector<vector<int>>& grid) {
    n = grid.size();

    // this will keep track of all of the nodes to explore. initially it will
    // have all of the positions of the 1s
    queue<vector<int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) q.push({i, j, 0});
      }
    }

    return bfs(grid, q);
  }
};