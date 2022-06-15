/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 515 - Find Largest Value in each Tree Row
 * @date 15-06-2022
 *
 * Runtime - 13 ms
 * Memory Usage - 22.1 MB
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
  vector<int> res;
  vector<int> largestValues(TreeNode *root) {
    if (!root) return res;

    helper(root, 0);
    return res;
  }

  void helper(TreeNode *root, int level) {
    if (!root) return;

    if (res.size() <= level) {
      res.push_back(root->val);
    }

    else {
      res[level] = max(res[level], root->val);
    }

    helper(root->left, level + 1);
    helper(root->right, level + 1);
  }
};