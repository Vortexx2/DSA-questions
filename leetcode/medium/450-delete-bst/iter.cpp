/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 450 - Delete Node in BST
 * @date 25-08-2021
 * 
 * Runtime - 32 ms O(logn)
 * Memory Usage - 32.5 MB O(1)
 */
#include <climits>
#include <iostream>
#include <tuple>
#include <utility>

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
  pair<TreeNode *, TreeNode *> findNodeAndParent(TreeNode *root, int key) {
    TreeNode *dad = nullptr;
    while (root) {
      if (root->val == key) return {root, dad};
      dad = root;

      if (root->val < key)
        root = root->right;
      else
        root = root->left;
    }
    return {nullptr, nullptr};
  }

  void replaceKid(TreeNode *parent, TreeNode *oldKid, TreeNode *newKid) {
    if (parent->left == oldKid)
      parent->left = newKid;
    else
      parent->right = newKid;
  }

  pair<TreeNode *, TreeNode *> findMaxInLeftSubtree(TreeNode *node) {
    TreeNode *parent = node;
    node = node->left;
    while (node->right) {
      parent = node;
      node = node->right;
    }

    return {node, parent};
  }

  void delNode(TreeNode *parent, TreeNode *node) {
    if (!node->left && !node->right)
      replaceKid(parent, node, nullptr);

    else if (!node->left)
      replaceKid(parent, node, node->right);
    else if (!node->right)
      replaceKid(parent, node, node->left);
    else {
      TreeNode *dad, *maxNode;
      tie(maxNode, dad) = findMaxInLeftSubtree(node);
      node->val = maxNode->val;
      delNode(dad, maxNode);
    }
  }

  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) return nullptr;
    TreeNode *dummy = new TreeNode(INT_MIN, nullptr, root);
    TreeNode *dad, *node;

    tie(node, dad) = findNodeAndParent(dummy, key);
    if (!node) return root;
    delNode(dad, node);
    return dummy->right;
  }
};