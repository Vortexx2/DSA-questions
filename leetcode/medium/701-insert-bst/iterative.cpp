/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 701 - Insert into a BST
 * @date 26-07-2021
 * 
 * Runtime - 84 ms
 * Memory Usage - 56.9 MB
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
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    TreeNode *newNode = new TreeNode(val);

    if (!root)
    {
      root = newNode;
      return root;
    }

    TreeNode *prev = nullptr, *curr = root;

    while (curr)
    {
      prev = curr;
      if (curr->val < val)
      {
        curr = curr->right;
      }

      else
      {
        curr = curr->left;
      }
    }

    if (prev->val < val)
      prev->right = newNode;
    else
      prev->left = newNode;

    return root;
  }
};