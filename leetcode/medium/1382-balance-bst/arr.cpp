/**
 * @file arr.cpp
 * @author Vortexx2
 * @brief Problem 1382 - Balance a BST
 * @date 17-06-2022
 * 
 * @approach Convert BST into inorder array. Use binary search method (dividing array
 * over and over into halves) to create BST
 * 
 * Runtime - 229 ms
 * Memory Usage - 63.3 MB
 */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
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
  TreeNode *balanceBST(TreeNode *root) {
    if (!root) return nullptr;

    vector<int> inorder;
    inorderTraversal(root, inorder);

    return constructBST(inorder, 0, inorder.size());
  }

  void inorderTraversal(TreeNode *root, vector<int> &arr) {
    if (!root) return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->val);
    inorderTraversal(root->right, arr);
  }

  TreeNode *constructBST(vector<int> &inorder, int start, int end) {
    if (start == end) return nullptr;
    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(inorder[mid]);

    root->left = constructBST(inorder, start, mid);
    root->right = constructBST(inorder, mid + 1, end);

    return root;
  }
};