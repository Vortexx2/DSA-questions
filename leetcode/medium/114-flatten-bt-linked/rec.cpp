/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 114 - Flatten BT to Linked List
 * @date 21-08-2021
 *
 * Runtime - 4 ms O(n)
 * Memory Usage - 12.6 MB O(h)
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
  void flatten(TreeNode *root) {
    if (!root) return;
    helper(root);
  }

  TreeNode *helper(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *left = helper(root->left), *right = helper(root->right);

    TreeNode *temp = root->right;
    if (root->left) {
      root->right = root->left;
      left->right = temp;
    }
    root->left = nullptr;

    if (right) return right;
    if (left) return left;
    return root;
  }
};