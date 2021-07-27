/**
 * @file q.cpp
 * @author Vortexx2
 * @brief Problem 919 - Complete Binary Tree Inserter
 * @date 26-07-2021
 * 
 * TLE
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

class CBTInserter
{
public:
  TreeNode *r;
  CBTInserter(TreeNode *root)
  {
    r = root;
  }

  int insert(int v)
  {
    TreeNode *newNode = new TreeNode(v);

    if (!r)
    {
      r = newNode;
      return v;
    }

    queue<TreeNode *> q;
    q.push(r);
    TreeNode *front;
    while (!q.empty())
    {
      front = q.front();
      if (!front->left)
      {
        front->left = newNode;
        break;
      }

      if (!front->right)
      {
        front->right = newNode;
        break;
      }

      q.push(front->left);
      q.push(front->right);
    }

    return front->val;
  }

  TreeNode *get_root()
  {
    return r;
  }
};
