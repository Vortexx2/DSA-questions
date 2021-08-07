/**
 * @file beautiful.cpp
 * @author Vortexx2
 * @brief Problem 429
 * @date 07-08-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 12 MB
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

    vector<Node *> level = {root};

    while (!level.empty())
    {
      vector<int> currNodes;
      vector<Node *> nextLevel;

      for (auto &node : level)
      {
        currNodes.push_back(node->val);

        for (auto &child : node->children)
          nextLevel.push_back(child);
      }

      res.push_back(currNodes);
      level = nextLevel;
    }

    return res;
  }
};