/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 958 - Check for completeness of BT
 * @date 09-11-2021
 *
 * Runtime - 0 ms
 * Memory Usage - 10.2 MB
 */
#include <iostream>
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
  unsigned int nodeCount;
  bool isCompleteTree(TreeNode *root) {
    nodeCount = countNodes(root);

    return completeHelper(root, 0);
  }

  // This method assigns an index to each node, which would be the value of the
  // index if all nodes were stored in an array in level order traversal
  bool completeHelper(TreeNode *root, unsigned int index) {
    if (!root) return true;

    if (index >= nodeCount) return false;

    return (completeHelper(root->left, 2 * index + 1) &&
            completeHelper(root->right, 2 * index + 2));
  }

  /**
   * @brief Counts the number of nodes in a tree recursively
   *
   * @param root Root of given subtree
   * @return unsigned int number of nodes in subtree
   */
  unsigned int countNodes(TreeNode *root) {
    if (!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};