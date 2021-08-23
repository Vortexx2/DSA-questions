/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 653 - Two Sum IV
 * @date 23-08-2021
 *
 * Runtime - 36 ms O(n)
 * Memory Usage - 38.9 MB O(n)
 */
#include <iostream>
#include <unordered_map>

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
  unordered_map<int, bool> dic;
  bool findTarget(TreeNode *root, int k) {
    if (!root) return false;

    auto itr = dic.find(k - root->val);
    if (itr != dic.end()) return true;

    dic.insert({root->val, true});

    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};