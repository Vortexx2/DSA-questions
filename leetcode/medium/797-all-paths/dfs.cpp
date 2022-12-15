/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 797 - All Paths From Source to Target
 * @approach Using a DFS exploration approach
 * @date 15-12-2022
 * 
 * Runtime - 25 ms O(n ^ 2)
 * Memory Usage - 13.3 MB O(n ^ 2)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int n;
  vector<vector<int>> res;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    res = {};

    n = graph.size();

    set<int> visited;
    visited.insert(0);
    vector<int> path = {0};

    for (auto& vertex : graph[0]) {
      dfs(graph, vertex, path, visited);
    }

    return res;
  }

  void dfs(vector<vector<int>>& graph, int vertex, vector<int>& path,
           set<int>& visited) {
    if (visited.find(vertex) != visited.end()) return;

    path.push_back(vertex);

    // if current vertex is goal, add path to res
    if (vertex == n - 1) {
      res.push_back(path);
      path.pop_back();
      return;
    }

    visited.insert(vertex);

    for (auto& nxt : graph[vertex]) {
      dfs(graph, nxt, path, visited);
    }

    visited.erase(vertex);
    path.pop_back();
  }
};