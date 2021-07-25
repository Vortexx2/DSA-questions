/**
 * @file beautiful.cpp
 * @author Vortexx2
 * @brief Problem 107 - Binary Tree Level Order Traversal II
 * @date 24-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 12.4 MB
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
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
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> res;
    if (!root)
      return res;

    vector<TreeNode *> level = {root};
    while (root && level.size())
    {
      vector<int> currNodes;
      vector<TreeNode*> nextLevel;

      for (auto &child: level) {
        currNodes.push_back(child->val);
        if (child->left) nextLevel.push_back(child->left);
        if (child->right) nextLevel.push_back(child->right);
      }

      res.push_back(currNodes);
      level = nextLevel;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};