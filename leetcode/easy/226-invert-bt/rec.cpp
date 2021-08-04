/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 226 - Invert BT
 * @date 03-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 9.6 MB
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
  TreeNode *invertTree(TreeNode *root)
  {
    if (!root)
      return nullptr;

    TreeNode *right = invertTree(root->right);
    root->right = invertTree(root->left);
    root->left = right;

    return root;
  }
};