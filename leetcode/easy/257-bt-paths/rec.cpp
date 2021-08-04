/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 257 - BT Paths
 * @date 04-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 13 MB
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
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> arr;
    string path = to_string(root->val);
    helper(root, arr, path);
    return arr;
  }

  void helper(TreeNode *node, vector<string> &arr, string path)
  {
    if (!node->left && !node->right)
    {
      arr.push_back(path);
      return;
    }

    if (node->left)
      helper(node->left, arr, path + "->" + to_string(node->left->val));
    if (node->right)
      helper(node->right, arr, path + "->" + to_string(node->right->val));
  }
};