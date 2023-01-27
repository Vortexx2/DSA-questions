/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 787 - Cheapest Flights within k Stops
 * @approach Using BFS with the condition that we add the next node only if the
 * new distance is lesser than the already computed distance, meaning a more
 * optimal path is being calculated
 * @date 28-01-2023
 *
 * Runtime - 24 ms
 * Memory Usage - 13.2 MB
 */
#include <bits/stdc++.h>

using namespace std;

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

    vector<int> distances(n, INT_MAX);

    // will store (node, dist)
    queue<pair<int, int>> q;
    q.push({src, 0});

    int currStops = -1;
    int currNode, currDist;

    while (!q.empty() && currStops < k) {
      int qSize = q.size();

      while (qSize--) {
        currNode = q.front().first, currDist = q.front().second;
        q.pop();

        for (auto &currPair : adj[currNode]) {
          int tempDist = currPair.second + currDist;

          // only add the node if the newly computed distance is shorter,
          // indicating that a more optimal path has been found
          if (tempDist < distances[currPair.first]) {
            q.push({currPair.first, tempDist});
            distances[currPair.first] = tempDist;
          }
        }
      }

      currStops++;
    }

    return distances[dst] == INT_MAX ? -1 : distances[dst];
  }
};