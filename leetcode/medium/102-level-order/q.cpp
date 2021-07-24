/**
 * @file q.cpp
 * @author Vortexx2
 * @brief Problem 102 - Binary Tree Level Order Traversal
 * @date 24-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 12.7 MB
 */
#include <iostream>
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;

    if (!root)
      return res;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    int currLevel = 0;
    while (!q.empty())
    {
      root = q.front().first, currLevel = q.front().second;
      q.pop();
      if (currLevel >= res.size())
      {
        vector<int> lv = {root->val};
        res.push_back(lv);
      }

      else
        res[currLevel].push_back(root->val);

      if (root->left)
        q.push({root->left, currLevel + 1});
      if (root->right)
        q.push({root->right, currLevel + 1});
    }

    return res;
  }
};