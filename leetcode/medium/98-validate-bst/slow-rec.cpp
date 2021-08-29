/**
 * @file slow-rec.cpp
 * @author Vortexx2
 * @brief Problem 98 - Validate BST
 * @date 29-08-2021
 * 
 * Runtime - 8 ms O(n^2)
 * Memory Usage - 21.6 MB O(n^2) [recursive stack]
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
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    if (!isLesser(root->left, root->val) || !isGreater(root->right, root->val)) return false;

    return isValidBST(root->left) && isValidBST(root->right);
  }

  bool isLesser(TreeNode *root, int &value) {
    if (!root) return true;

    return (root->val < value) && isLesser(root->left, value) &&
           isLesser(root->right, value);
  }

  bool isGreater(TreeNode *root, int &value) {
    if (!root) return true;

    return (root->val > value) && isGreater(root->left, value) &&
           isGreater(root->right, value);
  }
};