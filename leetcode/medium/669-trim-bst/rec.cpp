/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 669 - Trim a BST
 * @date 29-08-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 23.9 MB
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *trimBST(TreeNode *root, int &low, int &high) {
    if (!root) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    else if (root->val > high) return trimBST(root->left, low, high);
    else {
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
      return root;
    }
  }
};