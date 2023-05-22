/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 133 - Clone Graph
 * @approach Using recursive dfs
 * @date 22-05-2023
 * 
 * Runtime - 3 ms O(n ^ 2)
 * Memory Usage - 9.2 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

// Definition for a node
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  // maps (original, copy)
  unordered_map<Node*, Node*> dic;

  Node* dfs(Node* node) {
    Node* cp = new Node(node->val);
    dic.insert({node, cp});

    for (auto& nei : node->neighbors) {
      // neighbour already visited
      if (dic.find(nei) != dic.end())
        cp->neighbors.push_back(dic[nei]);

      // neighbour not visited, go through recursive cloning process
      else
        cp->neighbors.push_back(dfs(nei));
    }

    return cp;
  }

  Node* cloneGraph(Node* node) {
    // empty graph
    if (!node) return nullptr;

    dic = {};
    return dfs(node);
  }
};