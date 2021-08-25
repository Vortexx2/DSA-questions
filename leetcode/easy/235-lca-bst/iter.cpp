/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 235 - LCA of BST
 * @date 25-08-2021
 * 
 * Runtime - 24 ms O(logn)
 * Memory Usage - 23.3 MB O(1)
 */
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *minNode, *maxNode;
    if (p->val < q->val)
      minNode = p, maxNode = q;
    else
      minNode = q, maxNode = p;

    while (root->val < minNode->val || root->val > maxNode->val) {
      if (root->val < minNode->val)
        root = root->right;
      else
        root = root->left;
    }

    return root;
  }
};