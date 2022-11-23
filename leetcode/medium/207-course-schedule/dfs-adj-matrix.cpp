/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 207 - Course Schedule
 * @approach DFS using adjacency matrix
 * @date 23-11-2022
 * 
 * Runtime - 138 ms O(n ^ 2)
 * Memory Usage - 83.9 MB O(n ^ 2)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>(numCourses));

    for (auto& p : prerequisites) {
      adj[p[1]][p[0]] = 1;
    }

    set<int> visited;
    unordered_map<int, bool> isPossible;

    bool res;

    for (int i = 0; i < numCourses; i++) {
      if (isPossible[i]) continue;

      res = dfs(adj, i, visited, isPossible);

      if (!res) return false;
    }

    return true;
  }

  bool dfs(vector<vector<int>>& adj, int sRow, set<int>& visited,
           unordered_map<int, bool>& isPossible) {
    if (visited.find(sRow) != visited.end()) return false;

    if (isPossible[sRow]) return true;

    int numCourses = adj.size();

    visited.insert(sRow);

    bool res;

    for (int j = 0; j < numCourses; j++) {
      if (!adj[sRow][j]) continue;

      res = dfs(adj, j, visited, isPossible);

      if (!res) return false;
    }

    visited.erase(sRow);
    isPossible[sRow] = true;
    return true;
  }
};