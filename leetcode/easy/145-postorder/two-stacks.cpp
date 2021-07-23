/**
 * @file two-stacks.cpp
 * @author Vortexx2
 * @brief Problem 145 - Binary Tree Postorder Traversal
 * @date 23-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 8.5 MB
 */
#include <iostream>
#include <vector>
#include <deque>
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
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> res;

    if (!root)
      return res;

    stack<TreeNode *> st1, st2;

    st1.push(root);

    while (!st1.empty())
    {
      root = st1.top();
      st2.push(root);
      st1.pop();

      if (root->left)
        st1.push(root->left);

      if (root->right)
        st1.push(root->right);
    }

    while (!st2.empty())
    {
      res.push_back(st2.top()->val);
      st2.pop();
    }

    return res;
  }
};