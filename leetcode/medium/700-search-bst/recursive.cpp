/**
 * @file recursive.cpp
 * @author Vortexx2
 * @brief Problem 700 - Search in a BST
 * @date 25-07-2021
 * 
 * Runtime - 40 ms
 * Memory Usage - 34.7 MB
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
  TreeNode *searchBST(TreeNode *root, int val)
  {
    return helper(root, val);
  }

  TreeNode *helper(TreeNode *curr, int val)
  {
    if (!curr)
      return NULL;

    if (curr->val == val)
      return curr;

    TreeNode *res = NULL;
    if (curr->val < val)
      res = helper(curr->right, val);
    else
      res = helper(curr->left, val);

    return res;
  }
};