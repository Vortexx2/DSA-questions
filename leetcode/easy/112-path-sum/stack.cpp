/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 112 - Path Sum
 * @date 27-07-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 21.3 MB
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
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return false;
    stack<pair<TreeNode *, int>> st;
    st.push({root, root->val});

    while (root && !st.empty())
    {
      root = st.top().first;
      int currSum = st.top().second;
      st.pop();

      if (!root->left && !root->right && currSum == targetSum)
        return true;

      if (root->right)
        st.push({root->right, currSum + root->right->val});
      if (root->left)
        st.push({root->left, currSum + root->left->val});
    }

    return false;
  }
};