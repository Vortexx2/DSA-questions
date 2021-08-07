/**
 * @file rec-two-scans.cpp
 * @author Vortexx2
 * @brief Problem 1302 - Deepest Leaves Sum
 * @date 07-08-2021
 * 
 * Runtime - 32 ms
 * Memory Usage - 38.1 MB
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

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int deepestLeavesSum(TreeNode *root)
  {
    int maxDepth = depth(root);
    return helper(root, 1, maxDepth);
  }

  int depth(TreeNode *node)
  {
    if (!node)
      return 0;

    return 1 + max(depth(node->left), depth(node->right));
  }

  int helper(TreeNode *root, int depth, int maxLevel)
  {
    if (!root)
      return 0;
    if (depth == maxLevel)
      return root->val;

    return helper(root->left, depth + 1, maxLevel) + helper(root->right, depth + 1, maxLevel);
  }
};