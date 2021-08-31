/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 95 - Unique BST 2
 * @date 01-09-2021
 * 
 * Runtime - 16 ms
 * Memory Usage - 13.6 MB
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
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> res = {nullptr};

    for (int i = 1; i <= n; i++) {
      vector<TreeNode *> temp;
      for (int j = 0; j < res.size(); j++) {
        TreeNode *oldRoot = res[j];
        TreeNode *root = new TreeNode(i);
        TreeNode *target = clone(oldRoot);
        root->left = target;
        temp.push_back(root);

        if (oldRoot != nullptr) {
          TreeNode *tempOld = oldRoot;
          while (tempOld) {
            TreeNode *newNode = new TreeNode(i);
            TreeNode *tright = tempOld->right;
            tempOld->right = newNode;
            newNode->left = tright;
            TreeNode *target = clone(oldRoot);
            temp.push_back(target);
            tempOld->right = tright;
            tempOld = tempOld->right;
          }
        }
      }

      res = temp;
    }

    return res;
  }

  TreeNode *clone(TreeNode *root) {
    if (!root) return nullptr;
    TreeNode *newRoot =
        new TreeNode(root->val, clone(root->left), clone(root->right));
    return newRoot;
  }
};