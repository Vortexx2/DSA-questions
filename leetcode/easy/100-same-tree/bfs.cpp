/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 100
 * @date 02-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 14 MB
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({p, q});

    while (!st.empty())
    {
      TreeNode *node1 = st.top().first, *node2 = st.top().second;
      st.pop();

      if (node1 && node2)
      {
        if (node1->val != node2->val)
          return false;

        st.push({node1->right, node2->right});
        st.push({node1->left, node2->left});
      }

      else
      {
        if (node1 || node2)
          return false;
      }
    }

    return true;
  }
};