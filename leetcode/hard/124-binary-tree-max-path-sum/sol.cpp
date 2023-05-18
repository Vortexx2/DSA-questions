/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 124 - Binary Tree Maximum Path Sum
 * @apporach Using a recursive function
 * @date 18-05-2023
 * 
 * Runtime - 20 ms O(n)
 * Memory Usage - 27.6 MB O(log(n)) [Recursive stack]
 */
#include <bits/stdc++.h>

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
  int res;

  int helper(TreeNode *node) {
    /** Returns greatest sum of nodes including current, so that we can
     * propagate it upwards recursively */
    if (!node) return 0;

    int left = helper(node->left), right = helper(node->right);

    // takes the max of left, right or none of them, but current node has to be
    // included
    int curr = max(0, max(left, right)) + node->val;

    res = max(res,
              // check if a continuation between left right and current node
              // path can be max
              max(curr, left + right + node->val));

    return curr;
  }

  int maxPathSum(TreeNode *root) {
    res = INT_MIN;
    helper(root);
    return res;
  }
};