/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 226 - Invert Binary Tree
 * @date 04-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 9.7 MB
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
  TreeNode *invertTree(TreeNode *root)
  {
    if (!root)
      return nullptr;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
      TreeNode *node = st.top();
      st.pop();
      TreeNode *temp = node->left;
      node->left = node->right;
      node->right = temp;

      if (node->left)
        st.push(node->left);
      if (node->right)
        st.push(node->right);
    }

    return root;
  }
};