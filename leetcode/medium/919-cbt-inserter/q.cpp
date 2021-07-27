/**
 * @file q.cpp
 * @author Vortexx2
 * @brief Problem 919 CBT Inserter
 * @date 27-07-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 22.3 MB
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
  TreeNode *root;
  queue<TreeNode *> q;
  CBTInserter(TreeNode *r) : root(r)
  {
    queue<TreeNode *> temp;
    temp.push(r);

    while (!temp.empty())
    {
      TreeNode *node = temp.front();
      temp.pop();

      if (!node->left || !node->right)
        q.push(node);

      if (node->left)
        temp.push(node->left);

      if (node->right)
        temp.push(node->right);
    }
  }

  int insert(int v)
  {
    TreeNode *newNode = new TreeNode(v);
    q.push(newNode);
    TreeNode *node = q.front();

    if (!node->left)
      node->left = newNode;

    else
    {
      node->right = newNode;
      q.pop();
    }

    return node->val;
  }

  TreeNode *get_root()
  {
    return root;
  }
};
