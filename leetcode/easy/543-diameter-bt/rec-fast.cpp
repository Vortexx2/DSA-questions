/**
 * @file rec-fast.cpp
 * @author Vortexx2
 * @brief Problem 543 - Diameter BT
 * @date 05-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 20.2 MB
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
  int diameterOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;

    int d = 0;
    helper(root, d);
    return d;
  }

  int helper(TreeNode *node, int &d)
  {
    if (!node)
      return 0;

    int lHeight = helper(node->left, d);
    int rHeight = helper(node->right, d);
    d = max(d, lHeight + rHeight);
    return 1 + max(lHeight, rHeight);
  }
};