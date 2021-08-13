/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 1022 - Sum Of Root to Leaf Binary
 * @approach Adding current path binary value to the answer when encountering a leaf node, rather than making 2 passes like sol.cpp.
 * @date 13-08-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 16.7 MB
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
  int ans;
  int sumRootToLeaf(TreeNode *root)
  {
    vector<int> path;
    ans = 0;
    writePaths(root, path);

    return ans;
  }

  int binaryToInt(vector<int> &path)
  {
    int num = 0;
    for (int i = 0; i < path.size(); i++)
      num += (path[i] * pow(2, path.size() - i - 1));
    return num;
  }

  void writePaths(TreeNode *root, vector<int> &path)
  {
    if (!root)
      return;

    path.push_back(root->val);
    if (!root->left && !root->right)
      ans += binaryToInt(path);

    else
    {
      writePaths(root->left, path);
      writePaths(root->right, path);
    }

    path.pop_back();
  }
};