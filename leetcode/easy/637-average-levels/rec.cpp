/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 637 - Average Of Levels in BT
 * @date 21-08-2021
 *
 * Runtime - 12 ms
 * Memory Usage - 22.6 MB
 */
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    vector<pair<long, int>> help;
    helper(root, 0, help);
    for (int i = 0; i < help.size(); i++) {
      res.push_back((double)help[i].first / help[i].second);
    }

    return res;
  }

  void helper(TreeNode *root, int level, vector<pair<long, int>> &help) {
    if (!root) return;

    if (level >= help.size())
      help.push_back({root->val, 1});

    else
      help[level] = {help[level].first + root->val, help[level].second + 1};

    if (root->left) helper(root->left, level + 1, help);
    if (root->right) helper(root->right, level + 1, help);
  }
};