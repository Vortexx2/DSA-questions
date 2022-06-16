/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 99 - Recover BST
 * @date 16-06-2022
 * @approach Inorder traversal of a BST should be in ascending order. Figure out
 * which two nodes should be swapped to obtain ascending order.
 *
 * Runtime - 53 ms O(n)
 * Memory Usage - 58 MB O(n)
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
  vector<int> values;
  void recoverTree(TreeNode *root) {
    if (!root) return;

    inorderTraversal(root);
    auto [first, second] = findSwappedElems();

    findAndUpdate(root, first, second);
  }

  /**
   * @brief perform inorder traversal and write values to `values` vector
   *
   * @param root
   */
  void inorderTraversal(TreeNode *root) {
    if (!root) return;

    inorderTraversal(root->left);
    values.push_back(root->val);
    inorderTraversal(root->right);
  }

  /**
   * @brief Finds the swapped elements in a sorted array
   *
   * @return pair<int, int> the two swapped elements
   */
  pair<int, int> findSwappedElems() {
    int first = NULL, second = NULL;

    // previous in traversal
    int prev = values[0];

    for (int i = 1; i < values.size(); i++) {
      if (prev > values[i] && (!first)) first = prev;

      // if both swapped numbers are adjacent, will still work because will set
      // second if first is set
      if (prev > values[i] && (first)) second = values[i];

      prev = values[i];
    }

    return {first, second};
  }

  void findAndUpdate(TreeNode *root, const int &first, const int &second) {
    if (!root) return;

    findAndUpdate(root->left, first, second);
    if (root->val == first)
      root->val = second;
    else if (root->val == second)
      root->val = first;

    findAndUpdate(root->right, first, second);
  }
};