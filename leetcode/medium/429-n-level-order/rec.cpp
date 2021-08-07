/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 429 - N-ary Tree Level Order Traversal
 * @date 07-08-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 11.8 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<vector<int>> res;
    if (!root)
      return res;

    helper(root, res, 0);
    return res;
  }

  void helper(Node *node, vector<vector<int>> &res, int level)
  {
    if (level >= res.size())
      res.push_back({node->val});

    else
      res[level].push_back(node->val);

    for (auto &ch : node->children)
    {
      helper(ch, res, level + 1);
    }
  }
};