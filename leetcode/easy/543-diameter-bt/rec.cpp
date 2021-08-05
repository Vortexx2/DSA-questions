/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 543 - Diameter of BT
 * @date 05-08-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 14.3 MB
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

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int lDiam = diameterOfBinaryTree(root->left), rDiam = diameterOfBinaryTree(root->right);

    return max(lHeight + rHeight, max(lDiam, rDiam));
  }

  int height(TreeNode *node)
  {
    if (!node)
      return 0;

    return max(height(node->left), height(node->right)) + 1;
  }
};