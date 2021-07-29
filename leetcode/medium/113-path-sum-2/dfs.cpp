/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 113 - Path Sum II
 * @date 29-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 19.8 MB
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
#include <numeric>

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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    stack<pair<TreeNode *, vector<int>>> st;
    vector<vector<int>> res;

    st.push({root, {root->val}});
    while (!st.empty())
    {
      root = st.top().first;
      vector<int> temp = st.top().second;
      st.pop();

      if (!root->left && !root->right && accumulate(temp.begin(), temp.end(), 0) == targetSum)
        res.push_back(temp);

      vector<int> temp2(temp);
      if (root->left)
      {
        temp2.push_back(root->left->val);
        st.push({root->left, temp2});
      }

      vector<int> temp3(temp);
      if (root->right)
      {
        temp3.push_back(root->right->val);
        st.push({root->right, temp3});
      }
    }

    return res;
  }
};