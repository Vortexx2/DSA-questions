/**
 * @file easy.cpp
 * @author Vortexx2
 * @brief Problem 783 - Minimum Distance Between BST Nodes
 * @date 25-08-2021
 * 
 * Runtime - 0 ms O(n)
 * Memory Usage - 9.7 MB O(n)
 */
#include <algorithm>
#include <climits>
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
  int minDiffInBST(TreeNode *root) {
    helper(root);
    int minDiff = INT_MAX;
    for (int i = 1; i < inorder.size(); i++)
      minDiff = min(minDiff, inorder[i] - inorder[i - 1]);

    return minDiff;
  }

  void helper(TreeNode *root) {
    if (!root) return;
    helper(root->left);
    inorder.push_back(root->val);
    helper(root->right);
  }
};