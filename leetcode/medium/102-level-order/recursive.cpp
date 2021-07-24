/**
 * @file q.cpp
 * @author Vortexx2
 * @brief Problem 102 - Binary Tree Level Order Traversal
 * @date 24-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 13.8 MB
 */
#include <iostream>
#include <vector>
#include <deque>
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (!root)
      return res;

    helper(root, res, 0);

    return res;
  }

  void helper(TreeNode *curr, vector<vector<int>> &arr, int level)
  {

    if (!curr)
      return;

    if (level >= arr.size())
    {
      vector<int> lev;
      lev.push_back(curr->val);
      arr.push_back(lev);
    }

    else
      arr[level].push_back(curr->val);

    helper(curr->left, arr, level + 1);
    helper(curr->right, arr, level + 1);
  }
};