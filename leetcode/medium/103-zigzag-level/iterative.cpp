/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 103 - Zigzag Level Order Traversal
 * @date 11-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 12.1 MB
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

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    if (!root)
      return {};

    vector<vector<int>> res;
    vector<TreeNode *> level = {root};
    int i = 0;
    while (!level.empty())
    {
      vector<int> currNodes;
      vector<TreeNode *> nextLevel;

      for (auto &node : level)
      {
        currNodes.push_back(node->val);

        if (node->left)
          nextLevel.push_back(node->left);
        if (node->right)
          nextLevel.push_back(node->right);
      }

      if (i % 2 == 1)
        reverse(currNodes.begin(), currNodes.end());

      res.push_back(currNodes);
      level = nextLevel;
      i++;
    }

    return res;
  }
};