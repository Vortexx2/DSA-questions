/**
 * @file dijkstra.cpp
 * @author Vortexx2
 * @brief Problem 787 - Cheapest Flights Within K stops
 * @approach Using dijkstra's
 * 
 * @date 28-01-2023
 *
 * Runtime - 34 ms
 * Memory Usage - 15 MB 
 */
#include <bits/stdc++.h>

using namespace std;

class Compare {
 public:
  bool operator()(vector<int> &a, vector<int> &b) { return a[0] > b[0]; }
};

class Solution {
 public:
  // stores (nodeVal, dist)
  vector<vector<pair<int, int>>> adj;

  void fillAdj(vector<vector<int>> &edges) {
    for (auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
    }
  }

  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    adj.resize(n);
    fillAdj(flights);

    vector<int> stops(n, INT_MAX);

    // has values (distance, nodeVal, stops)
    priority_queue<vector<int>, vector<vector<int>>, Compare> q;
    q.push({0, src, -1});
    int currDist, currNode, currStops;

    while (!q.empty()) {
      auto temp = q.top();
      q.pop();

      currDist = temp[0], currNode = temp[1], currStops = temp[2];

      if (currStops > stops[currNode] || currStops > k) continue;

      stops[currNode] = currStops;

      if (currNode == dst) return currDist;

      for (auto &p : adj[currNode]) {
        // p is: (neighbour, distance)
        q.push({currDist + p.second, p.first, currStops + 1});
      }
    }

    return -1;
  }
};