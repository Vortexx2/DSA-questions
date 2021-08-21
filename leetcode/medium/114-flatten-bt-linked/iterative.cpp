/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 114 - Flatten BT to Linked List
 * @date 22-08-2021
 *
 * Runtime - 4 ms O(n)
 * Memory Usage - 12.7 MB O(1)
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
    TreeNode *node = root;
    while (node) {
      if (node->left) {
        TreeNode *pre = node->left;
        while (pre->right) pre = pre->right;

        pre->right = node->right;
        node->right = node->left;
        node->left = nullptr;
      }
      node = node->right;
    }
  }
};