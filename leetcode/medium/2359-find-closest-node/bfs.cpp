/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2359 - Find Closest Node
 * @approach Using bfs
 * @date 25-01-2023
 * 
 * Runtime - 528 ms O(n)
 * Memory Usage - 142.3 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> fillDistances(vector<int>& edges, int startNode) {
    int n = edges.size();
    vector<int> distances(n, INT_MAX);

    queue<int> q;
    q.push(startNode);
    int curr;
    int currDist = 0;
    set<int> visited;

    while (!q.empty()) {
      curr = q.front();
      q.pop();

      if (curr == -1) break;

      if (visited.find(curr) != visited.end()) continue;

      visited.insert(curr);

      distances[curr] = currDist++;

      q.push(edges[curr]);
    }

    return distances;
  }

  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    vector<int> d1 = fillDistances(edges, node1),
                d2 = fillDistances(edges, node2);

    int n = edges.size();
    int res = -1;
    int currMin = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (max(d1[i], d2[i]) < currMin) {
        res = i;
        currMin = max(d1[i], d2[i]);
      }
    }

    return res;
  }
};