/**
 * @file rec-btrack.cpp
 * @author Vortexx2
 * @brief Problem 113 - Path Sum II
 * @date 29-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 19.7 MB
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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> res;
    vector<int> path;

    helper(root, targetSum, path, res);
    return res;
  }

  void helper(TreeNode *curr, int targetSum, vector<int>& path, vector<vector<int>>& res)
  {
    if (!curr)
      return;
    path.push_back(curr->val);

    if (!curr->left && !curr->right && curr->val == targetSum)
    {
      res.push_back(path);
    }

    helper(curr->left, targetSum - curr->val, path, res);
    helper(curr->right, targetSum - curr->val, path, res);

    path.pop_back();
  }
};