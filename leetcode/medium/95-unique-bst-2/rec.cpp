/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 95 - Unique BST 2
 * @date 31-08-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 16.2 MB
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
  int number;
  vector<TreeNode *> generateTrees(int n) {
    number = n;
    return helper(1, n);
  }

  vector<TreeNode *> helper(int start, int end) {
    if (start > end) return {nullptr};

    vector<TreeNode *> res;

    for (int i = start; i <= end; i++) {
      vector<TreeNode *> left = helper(start, i - 1);
      vector<TreeNode *> right = helper(i + 1, end);
      for (auto &leftNode : left) {
        for (auto &rightNode : right) {
          TreeNode *root = new TreeNode(i, leftNode, rightNode);
          res.push_back(root);
        }
      }
    }

    return res;
  }
};