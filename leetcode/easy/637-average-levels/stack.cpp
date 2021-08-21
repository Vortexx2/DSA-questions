/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 637
 * @date 21-08-2021
 * 
 * Runtime - 18 ms
 * Memory Usage - 22.9 MB
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
    vector<TreeNode *> level = {root};

    while (!level.empty()) {
      vector<int> currentLevel;
      vector<TreeNode *> nextLevel;
      long sum = 0;

      for (auto &node : level) {
        sum += node->val;
        if (node->left) nextLevel.push_back(node->left);
        if (node->right) nextLevel.push_back(node->right);
      }

      res.push_back((double)(sum) / level.size());
      level = nextLevel;
    }

    return res;
  }
};