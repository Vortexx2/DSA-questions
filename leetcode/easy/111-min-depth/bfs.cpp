/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 111 - Min Depth Of BT
 * @date 02-08-2021
 * 
 * Runtime - 204 ms
 * Memory Usage - 144.7 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
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
  int minDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
      level++;

      for (int i = 0, n = q.size(); i < n; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (!node->left && !node->right)
          return level;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return level;
  }
};