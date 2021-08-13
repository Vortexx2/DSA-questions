/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1022 - Sum of Root to Leaf Binary Numbers
 * @date 13-08-2021
 * 
 * Runtime - 7 ms
 * Memory Usage - 18.5 MB
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
  int sumRootToLeaf(TreeNode *root)
  {
    vector<vector<int>> allPaths;
    vector<int> path;
    writePaths(root, path, allPaths);

    int res = 0;
    for (auto &pth : allPaths)
      res += binaryToInt(path);

    return res;
  }

  int binaryToInt(vector<int> &path)
  {
    int num = 0;
    for (int i = 0; i < path.size(); i++)
      num += (path[i] * pow(2, path.size() - i - 1));
    return num;
  }

  void writePaths(TreeNode *root, vector<int> &path, vector<vector<int>> &allPaths)
  {
    if (!root)
      return;

    path.push_back(root->val);
    if (!root->left && !root->right)
    {
      allPaths.push_back(path);
    }

    else
    {
      writePaths(root->left, path, allPaths);
      writePaths(root->right, path, allPaths);
    }

    path.pop_back();
  }
};