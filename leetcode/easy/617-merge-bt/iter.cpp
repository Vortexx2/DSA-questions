/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 617 - Merge Two BTs
 * @date 07-09-2021
 * 
 * Runtime - 32 ms
 * Memory Usage - 32.5 MB
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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({root1, root2});

    while (!st.empty()) {
      TreeNode *topLeft, *topRight;
      tie(topLeft, topRight) = st.top();
      st.pop();

      if (!topLeft || !topRight) continue;

      topLeft->val += topRight->val;

      if (!topLeft->left) topLeft->left = topRight->left;
      else st.push({topLeft->left, topRight->left});

      
      if (!topLeft->right) topLeft->right = topRight->right;
      else st.push({topLeft->right, topRight->right});
    }

    return root1;
  }
};