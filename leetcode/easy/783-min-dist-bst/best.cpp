/**
 * @file best.cpp
 * @author Vortexx2
 * @brief Problem 783 - Min Dist BST
 * @date 25-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 9.6 MB
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
  int res = INT_MAX, pre = -1;
  int minDiffInBST(TreeNode *root) {
    if (root->left) minDiffInBST(root->left);
    if (pre >= 0) res = min(res, root->val - pre);
    pre = root->val;
    if (root->right) minDiffInBST(root->right);
    return res;
  }
};