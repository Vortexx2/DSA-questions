/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 897 - Increasing Order Search Tree
 * @date 14-10-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 7.5 MB
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

class Solution {
 public:
  TreeNode *curr;
  TreeNode *increasingBST(TreeNode *root) {

    TreeNode *temp = new TreeNode(0);
    curr = temp;
    inorder(root);

    return temp->right;

  }

  void inorder(TreeNode *root) {
    if (!root) return;

    inorder(root->left);
    root->left = nullptr;
    curr->right = root;
    curr = root;
    inorder(root->right);
  }
};