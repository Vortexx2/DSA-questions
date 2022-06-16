/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 99 - Recover BST
 * @date 16-06-2022
 * @approach Inorder traversal of a BST should be in ascending order. Do all of the business logic
 * while performing inorder traversal.
 * 
 * Runtime - 63 ms O(n)
 * Memory Usage - 57.7 MB O(n)
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
  TreeNode *firstNode, *secondNode, *prevNode;
  void recoverTree(TreeNode *root) {
    if (!root) return;

    firstNode = secondNode = prevNode = nullptr;
    inorderTraversal(root);

    cout << firstNode->val << "\t" << secondNode->val << '\t';

    int temp = firstNode->val;
    firstNode->val = secondNode->val;
    secondNode->val = temp;
  }

  /**
   * @brief perform inorder traversal and in the processing on the current node
   * section perform business logic
   *
   * @param root
   */
  void inorderTraversal(TreeNode *root) {
    if (!root) return;

    inorderTraversal(root->left);

    if (prevNode && root->val < prevNode->val && !firstNode)
      firstNode = prevNode;

    if (prevNode && root->val < prevNode->val && firstNode)
      secondNode = root;

    prevNode = root;

    inorderTraversal(root->right);
  }
};