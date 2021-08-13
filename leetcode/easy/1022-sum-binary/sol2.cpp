/**
 * @file sol2.cpp
 * @author Vortexx2
 * @brief Problem 1022 - Sum Of Root to Leaf Binary
 * @approach Adding current path binary value to the answer when encountering a leaf node, rather than making 2 passes like sol.cpp.
 * @date 13-08-2021
 * 
 * Runtime - 3 ms
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
    ans = 0;
    writePaths(root, 0);

    return ans;
  }

  void writePaths(TreeNode *root, int running)
  {
    if (!root)
      return;

    running = running << 1 | root->val;
    if (!root->left && !root->right)
      ans += running;

    else
    {
      writePaths(root->left, running);
      writePaths(root->right, running);
    }
  }
};