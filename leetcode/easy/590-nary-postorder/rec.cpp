/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 590 - Nary Postorder Traversal
 * @date 17-08-2021
 * 
 * Runtime - 16 ms
 * Memory Usage - 11 MB
 */
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<int> postorder(Node* root) {
    if (!root) return {};

    vector<int> res;
    helper(root, res);
    return res;
  }

  void helper(Node *root, vector<int> &res) {
    if (!root) return;

    for (auto &node: root->children) helper(node, res);

    res.push_back(root->val);
  }
};