/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 104 - Maximum Depth Of BT
 * @date 02-08-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 18.9 MB
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
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;

    q.push(root);
    int level = 0;

    while (!q.empty())
    {
      level++;

      for (int i = 0, s = q.size(); i < s; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return level;
  }
};