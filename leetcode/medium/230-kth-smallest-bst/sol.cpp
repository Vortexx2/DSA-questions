/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 230 - Kth Smallest Element in BST
 * @date 13-10-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 24.2 MB
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
  int count = 0;

  int kthSmallest(TreeNode *root, int &k) {
    if (!root) return -1;

    int left = kthSmallest(root->left, k);

    if (left == -1) {
      count++;

      if (count == k) return root->val;

      int right = kthSmallest(root->right, k);
      if (right != -1)
        return right;

      else
        return right;

    }

    else
      return left;
  }
};