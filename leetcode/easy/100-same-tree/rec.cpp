/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 100 - Same Tree
 * @date 02-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 9.9 MB
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (!p && !q)
      return true;
    if (!p || !q)
      return false;
    if (p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};