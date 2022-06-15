/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 515 - Find Largest Value in each Tree Row
 * @date 15-06-2022
 * 
 * Runtime - 20 ms
 * Memory Usage - 22.6 MB 
 */
#include <climits>
#include <iostream>
#include <queue>
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
  vector<int> largestValues(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    res.push_back(root->val);  // root level max value is root

    vector<TreeNode *> level;
    level.push_back(root);

    while (!level.empty()) {
      vector<TreeNode *> nextLevel;

      int currMax = INT_MIN;

      for (TreeNode *node : level) {
        if (node->left) {
          currMax = max(currMax, node->left->val);
          nextLevel.push_back(node->left);
        }

        if (node->right) {
          currMax = max(currMax, node->right->val);
          nextLevel.push_back(node->right);
        }
      }

      level = nextLevel;
      if (!nextLevel.empty()) res.push_back(currMax);
    }

    return res;
  }
};