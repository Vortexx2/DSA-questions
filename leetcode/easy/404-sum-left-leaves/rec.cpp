/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 404 - Sum Left Leaves
 * @date 05-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 13.4 MB
 */

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
  int sumOfLeftLeaves(TreeNode *root, bool left = false)
  {
    if (left && !root->left && !root->right)
      return root->val;

    int a = 0;
    if (root->left)
      a += sumOfLeftLeaves(root->left, true);
    if (root->right)
      a += sumOfLeftLeaves(root->right, false);

    return a;
  }
};