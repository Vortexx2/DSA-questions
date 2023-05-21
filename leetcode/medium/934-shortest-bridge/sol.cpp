/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 934 - Shortest Bridge
 * Using DFS to bifurcate first island and then BFS to find closest route
 * @date 21-05-2023
 * 
 * Runtime - 109 ms O(n ^ 2)
 * Memory Usage - 24.3 MB O(n ^ 2)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
  int rows, cols;
  set<pair<int, int>> visited;

  void dfs(int i, int j, vector<vector<int>>& grid) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) return;

    if (
        // cell is water
        !grid[i][j] ||
        // cell was visited
        visited.find({i, j}) != visited.end())
      return;

    visited.insert({i, j});
    for (auto& p : dirs) {
      dfs(i + p.first, j + p.second, grid);
    }
  }

  int bfsPart(vector<vector<int>>& grid) {
    // will store (i, j)
    queue<pair<int, int>> q;

    // push all elements in first island into frontier
    for (auto it = visited.begin(); it != visited.end(); it++)
      q.push({it->first, it->second});

    int dist = 0;

    while (!q.empty()) {
      int qSize = q.size();

      while (qSize--) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();

        for (auto& p : dirs) {
          int new_i = i + p.first, new_j = j + p.second;
          if (new_i < 0 || new_i >= rows || new_j < 0 || new_j >= cols)
            continue;

          // part of visited, don't explore that
          if (visited.find({new_i, new_j}) != visited.end()) continue;

          if (grid[new_i][new_j]) return dist;

          q.push({new_i, new_j});
          visited.insert({new_i, new_j});
        }
      }

      dist++;
    }

    return -1;
  }

  int shortestBridge(vector<vector<int>>& grid) {
    // there are exactly 2 islands in the matrix

    rows = grid.size(), cols = grid[0].size();

    visited = {};

    // add 1 island to frontier
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // we don't want to start with water
        if (grid[i][j] == 0) continue;

        dfs(i, j, grid);
        return bfsPart(grid);
      }
    }

    return -1;
  }
};