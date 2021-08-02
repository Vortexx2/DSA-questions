/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 101 - Symmetric Tree
 * @date 02-08-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 16.8 MB
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
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;

    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root->left, root->right});

    while (!q.empty())
    {
      TreeNode *node1 = q.front().first, *node2 = q.front().second;
      q.pop();

      if (node1 && node2)
      {
        if (node1->val != node2->val)
          return false;

        q.push({node1->left, node2->right});
        q.push({node1->right, node2->left});
      }

      else
      {
        if (node1 || node2)
          return false;
      }
    }

    return true;
  }
};