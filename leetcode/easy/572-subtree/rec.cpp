/**
 * @file rec.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @date 2021-08-09
 * 
 * 
 */
#include <iostream>
#include <algorithm>

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
  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    return checkSubtree(root, subRoot, subRoot);
  }

  bool checkSubtree(TreeNode *root, TreeNode *subRoot, TreeNode *subRootOrigin)
  {
    if (!root && !subRoot)
      return true;
    if (!root || !subRoot)
      return false;

    if (root->val == subRoot->val)
    {
      if (checkSubtree(root->left, subRoot->left, subRootOrigin) && checkSubtree(root->right, subRoot->right, subRootOrigin))
        return true;
    }

    if (subRoot == subRootOrigin)
      return checkSubtree(root->left, subRootOrigin, subRootOrigin) || checkSubtree(root->right, subRootOrigin, subRootOrigin);

    return false;
  }
};