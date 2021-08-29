/**
 * @file inorder.cpp
 * @author Vortexx2
 * @brief Problem 98 - Validate BST
 * @date 29-08-2021
 * 
 * Runtime - 8 ms O(n)
 * Memory Usage - 21.6 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <string>

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
  long prev = LONG_MIN;
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    if (!isValidBST(root->left)) return false;
    if (root->val <= prev) return false;
    prev = root->val;
    return isValidBST(root->right);
  }
};