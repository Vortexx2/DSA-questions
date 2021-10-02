/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 173 - BST Iterator
 * @date 02-10-2021
 * 
 * Runtime - 47 ms
 * Memory Usage - 24.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BSTIterator {
 public:
  vector<int> inorder;
  int i;
  BSTIterator(TreeNode *root) {
    i = 0;
    helper(root);
  }

  void helper(TreeNode* root) {
    if (!root) return;

    helper(root->left);
    inorder.push_back(root->val);
    helper(root->right);
  }

  int next() {
    return inorder[i++];
  }

  bool hasNext() {
    return i != (inorder.size() - 1);
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */