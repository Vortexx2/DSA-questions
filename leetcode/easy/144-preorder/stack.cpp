/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 144 - Binary Tree Preorder Traversal
 * @date 20-07-2021
 * 
 * Runtime - 4 ms
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
  /**
   * @brief Using a stack to store addresses of previous nodes where tree branched.
   * 
   * @param root 
   * @return vector<int> 
   */
  vector<int> preorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> res;

    while (true)
    {

      while (root)
      {
        res.push_back(root->val);

        st.push(root);
        root = root->left;
      }

      if (st.empty())
        break;

      root = st.top();
      st.pop();
      root = root->right;
    }

    return res;
  }
};