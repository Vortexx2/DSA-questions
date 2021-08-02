/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 104 - Maximum Depth Of Binary Tree
 * @date 02-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 18.9 MB
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
  int maxDepth(TreeNode *root, int level = 1)
  {
    if (!root)
      return level - 1;

    int a = maxDepth(root->left, level + 1);
    int b = maxDepth(root->right, level + 1);
    return max(a, b);
  }
};