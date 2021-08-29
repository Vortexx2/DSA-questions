/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 98 - Validate BST
 * @date 29-08-2021
 * 
 * Runtime - 4 ms O(n)
 * Memory Usage - 21.5 MB O(h)
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
  bool isValidBST(TreeNode *root, long min = LONG_MIN, long max = LONG_MAX) {
    if (!root) return true;

    return (root->val > min && root->val < max &&
            isValidBST(root->left, min, root->val) &&
            isValidBST(root->right, root->val, max));
  }
};