/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 236 - Lowest Common Ancestor
 * @date 07-08-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 14.1 MB
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root)
      return nullptr;

    if (root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q),
             *right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;

    return left ? left : right;
  }
};