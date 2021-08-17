/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 129 - Sum Root to Leaf Numbers
 * @approach Iterative Preorder Approach
 * @date 17-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 9.2 MB
 */
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int sumNumbers(TreeNode *root) {
    int res = 0;
    stack<pair<TreeNode *, int>> st;
    st.push({root, root->val});

    while (!st.empty()) {
      TreeNode *top = st.top().first;
      int running = st.top().second;
      st.pop();

      if (!top->left && !top->right)
        res += running;

      else {
        if (top->left) st.push({top->left, running * 10 + top->left->val});
        if (top->right) st.push({top->right, running * 10 + top->right->val});
      }
    }

    return res;
  }
};