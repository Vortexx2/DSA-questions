/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 107 - Binary Tree Level Order Traversal II
 * @date 25-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 12.4 MB
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
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    if (!root)
      return {};
    queue<pair<TreeNode *, int>> q;
    stack<pair<TreeNode *, int>> st;

    q.push({root, 0});
    int level;

    while (!q.empty())
    {
      TreeNode *front = q.front().first;
      level = q.front().second;

      if (front->left)
        q.push({front->left, level + 1});
      if (front->right)
        q.push({front->right, level + 1});

      q.pop();
      st.push({front, level});
    }

    vector<vector<int>> res(level + 1);

    while (!st.empty())
    {
      TreeNode *top = st.top().first;
      int lv = st.top().second;

      res[level - lv].push_back(top->val);
      st.pop();
    }

    return res;
  }
};