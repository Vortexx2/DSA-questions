/**
 * @file recursive.cpp
 * @author Vortexx2
 * @brief Problem 112 - Path Sum
 * @date 27-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 21.3 MB
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
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return false;

    if (!root->left && !root->right && targetSum == root->val)
      return true;

    int a = targetSum - root->val;
    return hasPathSum(root->left, a) || hasPathSum(root->right, a);
  }
};