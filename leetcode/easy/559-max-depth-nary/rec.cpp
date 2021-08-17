/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 559 - Maximum Depth of N-ary Tree
 * @date 17-08-2021
 *
 * Runtime - 12 ms
 * Memory Usage - 10.6 MB
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
  int maxDepth(Node* root) {
    if (!root) return 0;
    int maxLevel = 0;
    for (auto& node : root->children) maxLevel = max(maxLevel, maxDepth(node));
    return maxLevel + 1;
  }
};