/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1008 - Construct BST from Preorder Traversal
 * 
 * Runtime - 0 ms O(n)
 * Memory Usage - 16.6 MB O(n)
 * @date 2024-08-26
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int index;
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        index = 0;
        return buildTree(preorder, INT_MAX);
    }

    TreeNode *buildTree(vector<int> &preorder, int upperBound) {
        if (index >= preorder.size() || preorder[index] >= upperBound)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[index++]);

        root->left = buildTree(preorder, root->val);
        root->right = buildTree(preorder, upperBound);

        return root;
    }
};