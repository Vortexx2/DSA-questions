/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 1519 - Number Of Nodes in the Subtree with the Same Label
 * @date 12-01-2023
 * 
 * Runtime - 724 ms
 * Memory Usage - 242 MB exponential
 */
#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) { return (int)(c - 'a'); }

class Solution {
 public:
  unordered_map<int, vector<int>> adj;
  vector<int> res;

  void fillAdj(vector<vector<int>> &edges) {
    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
  }

  vector<int> helper(int curr, int parent, string &labels) {
    vector<int> counter(26, 0);

    for (auto &child : adj[curr]) {
      if (child == parent) continue;

      auto subtreeCounter = helper(child, curr, labels);

      for (int i = 0; i < 26; i++) {
        counter[i] += subtreeCounter[i];
      }
    }

    res[curr] = ++counter[charToInt(labels[curr])];
    return counter;
  }

  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    fillAdj(edges);

    res.resize(n);

    helper(0, -1, labels);

    return res;
  }
};