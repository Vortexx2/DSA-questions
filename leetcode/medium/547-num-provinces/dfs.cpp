/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 547 - Number of Provinces
 * @approach - Using DFS
 * @date 06-11-2022
 *
 * Runtime - 28 ms O(n * n)
 * Memory Usage - 13.6 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int res = 0;

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i]) break;

        if (i == j) continue;

        visited[i] = true;
        if (isConnected[i][j]) dfs(isConnected, visited, j);
        visited[i] = false;
      }

      if (!visited[i]) res++;

      visited[i] = true;
    }

    return res;
  }

  void dfs(vector<vector<int>>& graph, vector<bool>& visited, int pos) {
    if (visited[pos]) return;

    visited[pos] = true;
    for (int i = 0; i < graph.size(); i++) {
      if (graph[pos][i]) dfs(graph, visited, i);
    }
  }
};