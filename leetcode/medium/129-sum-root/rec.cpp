/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 129 - Sum Root to Leaf Numbers
 * @date 17-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 9.1 MB
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
  int sum;
  int sumNumbers(TreeNode *root) {
    sum = 0;
    helper(root, 0);
    return sum;
  }

  void helper(TreeNode *root, int running) {
    running = running * 10 + root->val;

    if (!root->left && !root->right) sum += running;

    if (root->left) helper(root->left, running);
    if (root->right) helper(root->right, running);
  }
};