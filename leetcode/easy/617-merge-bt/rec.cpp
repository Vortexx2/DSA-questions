/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 617 - Merge Two BTs
 * @date 07-09-2021
 * 
 * Runtime - 40 ms
 * Memory Usage - 34.8 MB
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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) return nullptr;
    if (!root1) {
      return new TreeNode(root2->val, mergeTrees(nullptr, root2->left),
                          mergeTrees(nullptr, root2->right));
    }

    if (!root2) {
      return new TreeNode(root1->val, mergeTrees(root1->left, nullptr),
                          mergeTrees(root1->right, nullptr));
    }

    return new TreeNode(root1->val + root2->val,
                        mergeTrees(root1->left, root2->left),
                        mergeTrees(root1->right, root2->right));
  }
};