/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 897 - Increasing Order Search Tree
 * @date 14-10-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 8.1 MB
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
  vector<int> inorder;
  TreeNode *increasingBST(TreeNode *root) {
    inorderCreator(root);

    TreeNode *temp = new TreeNode(0), *curr = temp;

    for (int &num : inorder) {
      curr->right = new TreeNode(num);

      curr = curr->right;
    }

    return temp->right;
  }

  void inorderCreator(TreeNode *root) {
    if (!root) return;

    inorderCreator(root->left);
    inorder.push_back(root->val);
    inorderCreator(root->right);
  }
};