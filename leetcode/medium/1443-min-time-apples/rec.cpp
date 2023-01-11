/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 1443 - MInimum Time to Collect All Apples in a Tree
 * @date 11-01-2023
 *
 * Runtime - 213 ms O(n)
 * Memory Usage - 68.8 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // maps vertex to vertices that it is connected to
  unordered_map<int, vector<int>> adj;
  int appleCount, applesEncountered = 0;

  void fillAdj(vector<vector<int>>& edges) {
    for (auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
  }

  void countApples(vector<bool>& hasApple) {
    appleCount = 0;

    for (int i = 0; i < hasApple.size(); i++) {
      if (hasApple[i]) appleCount++;
    }
  }

  int dfs(int curr, int parent, vector<bool>& hasApple) {
    int currTime = 0, childTime = 0;

    for (auto& child : adj[curr]) {
      if (!appleCount) break;

      if (child == parent) continue;

      childTime = dfs(child, curr, hasApple);

      if (childTime || hasApple[child]) {
        if (hasApple[child]) appleCount--;
        currTime += (childTime + 2);
      }
    }

    return currTime;
  }

  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    fillAdj(edges);

    countApples(hasApple);

    return dfs(0, -1, hasApple);
  }
};