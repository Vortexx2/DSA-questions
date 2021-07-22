/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 94 - Binary Tree Inorder Traversal
 * @date 21-07-2021
 * 
 * Runtime - 0 ms 
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
  vector<int> inorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> res;

    while (true)
    {
      while (root)
      {
        st.push(root);
        root = root->left;
      }

      if (st.empty())
        break;

      root = st.top();
      st.pop();
      res.push_back(root->val);
      root = root->right;
    }

    return res;
  }
};