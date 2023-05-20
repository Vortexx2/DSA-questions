/**
 * @file graph-colouring.cpp
 * @author Vortexx2
 * @brief Problem 785 - Is Graph Bipartite?
 * @approach Using graph colouring
 * @date 20-05-2023
 * 
 * Runtime - 27 ms O(E + V)
 * Memory - 13.7 MB O(V)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();

    if (n <= 1) return true;

    // 0 - uncoloured, 1 - red, -1 - blue
    vector<int> nodeColours(n, 0);

    queue<int> q;

    for (int i = 0; i < n; i++) {
      // already visited
      if (nodeColours[i] != 0) continue;

      q.push(i);
      nodeColours[i] = 1;

      int curr;
      while (!q.empty()) {
        curr = q.front();
        q.pop();

        for (auto& n : graph[curr]) {
          if (nodeColours[n] == nodeColours[curr])
            return false;

          else if (nodeColours[n] == 0) {
            nodeColours[n] = -nodeColours[curr];
            q.push(n);
          }
        }
      }
    }

    return true;
  }
};