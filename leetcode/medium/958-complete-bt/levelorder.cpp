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
    bool prevNotComplete = false;

    while (!level.empty()) {
      vector<TreeNode *> nextLevel;

      for (TreeNode *&node : level) {
        if (!node->left && node->right) return false;

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