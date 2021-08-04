/**
 * @file st.cpp
 * @author Vortexx2
 * @brief Problem 404 - Sum Left Leaves
 * @date 05-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 13.4 MB
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
  int sumOfLeftLeaves(TreeNode *root)
  {
    stack<TreeNode *> st;
    st.push(root);
    int res = 0;

    while (!st.empty())
    {
      root = st.top();
      st.pop();

      if (root->right)
        st.push(root->right);
      if (root->left)
      {
        if (!root->left->left && !root->left->right)
          res += root->left->val;
        else
          st.push(root->left);
      }
    }

    return res;
  }
};