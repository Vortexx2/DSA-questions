/**
 * @file union-find.cpp
 * @author Vortexx2
 * @brief Problem 1971 - Find if Path Exists in Graph
 * @approach Using Union Find datastructure instead of visited set.
 * @date 16-01-2023
 * 
 * Runtime - 583 ms O(n * logn)
 * Memory Usage - 159.5 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int size) {
    parent.resize(size);
    rank.resize(size, 0);

    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    while (parent[x] != x) x = parent[x];

    return parent[x];
  }

  void unionOperation(int x, int y) {
    int xset = find(x), yset = find(y);

    if (rank[xset] > rank[yset])
      parent[yset] = xset;

    else if (rank[yset] > rank[xset])
      parent[xset] = yset;

    // if both are equal
    else {
      parent[xset] = yset;
      rank[yset]++;
    }
  }
};

class Solution {
 public:
  vector<vector<int>> adj;

  void fillAdj(vector<vector<int>>& edges) {
    for (auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
  }

  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    adj.resize(n, {});

    fillAdj(edges);

    UnionFind dsu(n);
    queue<int> q;
    q.push(source);
    int currNode;

    while (!q.empty()) {
      currNode = q.front();
      q.pop();

      if (currNode == destination) return true;

      for (auto& child : adj[currNode]) {
        if (child == destination) return true;

        if (dsu.find(child) == dsu.find(source)) continue;

        q.push(child);
        dsu.unionOperation(source, child);
      }
    }

    return false;
  }
};