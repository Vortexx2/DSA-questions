/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 653 - Two Sum IV
 * @date 23-08-2021
 * 
 * Runtime - 24 ms O(n)
 * Memory Usage - 36.8 MB O(h)
 */
#include <iostream>
#include <stack>
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
  bool findTarget(TreeNode *root, int k) {
    stack<TreeNode *> lStack, rStack;
    pushLeft(root, lStack);
    pushRight(root, rStack);

    int left = nextLeft(lStack), right = nextRight(rStack);
    while (left < right) {
      if (left + right == k) return true;
      if (left + right < k) left = nextLeft(lStack);
      else right = nextRight(rStack);
    }
    return false;
  }

  void pushLeft(TreeNode *root, stack<TreeNode *> &st) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  void pushRight(TreeNode *root, stack<TreeNode *> &st) {
    while (root) {
      st.push(root);
      root = root->right;
    }
  }

  int nextLeft(stack<TreeNode *> &st) {
    TreeNode *node = st.top();
    st.pop();
    pushLeft(node->right, st);
    return node->val;
  }

  int nextRight(stack<TreeNode *> &st) {
    TreeNode *node = st.top();
    st.pop();
    pushRight(node->left, st);
    return node->val;
  }
};