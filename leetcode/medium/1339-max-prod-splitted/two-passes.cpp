/**
 * @file two-passes.cpp
 * @author Vortexx2
 * @brief Problem 1339 - Max Prod of splitted BT
 * @date 21-08-2021
 * 
 * Runtime - 116 ms
 * Memory Usage - 90.6 MB
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
  long long res = 0;
  int maxProduct(TreeNode *root) {
    long long total = totalTreeSum(root);
    sumUnder(root, total);
    return res % (int)(1e9 + 7);
  }

  long long totalTreeSum(TreeNode *root) {
    if (!root) return 0;
    return root->val + totalTreeSum(root->left) + totalTreeSum(root->right);
  }

  int sumUnder(TreeNode *root, long long &total) {
    if (!root) return 0;

    int sumUnderLeft = sumUnder(root->left, total),
        sumUnderRight = sumUnder(root->right, total);

    res = max({res, (total - sumUnderLeft) * sumUnderLeft,
               (total - sumUnderRight) * sumUnderRight});
    return sumUnderLeft + sumUnderRight + root->val;
  }
};