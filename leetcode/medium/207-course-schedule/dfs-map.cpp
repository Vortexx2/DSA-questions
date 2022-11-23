/**
 * @file dfs-map.cpp
 * @author Vortexx2
 * @brief Problem 207 - Course Schedule
 * @approach Using recursive DFS with map
 * @date 23-11-2022
 * 
 * Runtime - 66 ms O(n ^ 2)
 * Memory Usage - 16 MB O(n ^ 2)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < numCourses; i++) adj[i] = {};

    for (auto &p : prerequisites) {
      adj[p[1]].push_back(p[0]);
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

  bool dfs(unordered_map<int, vector<int>> &adj, int sRow, set<int> &visited,
           unordered_map<int, bool> &isPossible) {
    if (visited.find(sRow) != visited.end()) return false;

    if (isPossible[sRow]) return true;

    visited.insert(sRow);
    bool res;

    for (auto &vertex : adj[sRow]) {
      res = dfs(adj, vertex, visited, isPossible);

      if (!res) return false;
    }

    isPossible[sRow] = true;
    visited.erase(sRow);
    return true;
  }
};