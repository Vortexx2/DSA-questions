/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 110 - Balanced Binary Tree
 * @date 02-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 21 MB
 */
#include <bits-stdc++.h>

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
  bool isBalanced(TreeNode *root)
  {
    if (!root)
      return true;

    return helper(root) != -1;
  }

  int helper(TreeNode *node)
  {
    if (!node)
      return 0;

    int a = helper(node->left);
    if (a == -1)
      return -1;
    int b = helper(node->right);
    if (b == -1)
      return -1;

    if (abs(b - a) > 1)
      return -1;

    if (a > b)
      return a + 1;
    else
      return b + 1;
  }
};