/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 145 - Binary Tree Postorder Traversal
 * @date 23-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 8.3 MB
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

    stack<TreeNode *> st;

    while (true)
    {
      // Go to the left most point of the current node (root)
      while (root)
      {
        st.push(root);
        root = root->left;
      }

      if (st.empty())
        break;

      root = st.top();
      TreeNode *prev = NULL;
      while ((!root->right) || (root->right == prev))
      {
        res.push_back(root->val);
        st.pop();
        // After pop, accessing st.top() might cause memory issue
        if (st.empty())
          return res;
        prev = root;
        root = st.top();
      }

      root = root->right;
    }

    return res;
  }
};