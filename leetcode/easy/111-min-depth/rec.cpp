/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 111 - Minimum Depth Of BT
 * @date 02-08-2021
 * 
 * Runtime - 240 ms
 * Memory Usage - 146.7 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
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
  int minDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return 1;

    int a = INT_MAX, b = INT_MAX;
    if (root->left)
      a = minDepth(root->left);
    if (root->right)
      b = minDepth(root->right);
    return min(a, b) + 1;
  }
};