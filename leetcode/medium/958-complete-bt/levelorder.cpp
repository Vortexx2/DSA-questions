/**
 * @file levelorder.cpp
 * @author Vortexx2
 * @brief Problem 958 - Check Completeness of BT
 * @approach - Using iterative level order traversal
 * @date 09-11-2021
 *
 * Runtime - 4 ms
 * Memory Usage - 10.5 MB
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
  bool isCompleteTree(TreeNode *root) {
    if (!root) return true;

    vector<TreeNode *> level = {root};
    // has to be declared in the most outter scope possible, if it ever turns
    // true and we encounter another child, we know tree is not balanced
    bool prevNotComplete = false;

    while (!level.empty()) {
      vector<TreeNode *> nextLevel;

      for (TreeNode *&node : level) {
        // node has right child but not left child
        if (!node->left && node->right) return false;

        // if any of previous nodes missed a child, but current node has a
        // child, not complete
        if (prevNotComplete && (node->left || node->right)) return false;

        if (node->left)
          nextLevel.push_back(node->left);
        else
          prevNotComplete = true;

        if (node->right)
          nextLevel.push_back(node->right);
        else
          prevNotComplete = true;
      }

      level = nextLevel;
    }

    return true;
  }
};