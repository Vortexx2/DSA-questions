/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 230 - Kth Smallest Element in a BST
 * 
 * Runtime - 7 ms O(n)
 * Memory Usage - 22.71 MB O(log n)
 * @date 2024-08-27
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
    int count = 0;
    int k;
    int kthSmallest(TreeNode *root, int k) {
        this->k = k;
        return helper(root);
    }

    int helper(TreeNode *root) {
        if (!root) return -1;

        int left = helper(root->left);
        if (left != -1) return left;
        count++;
        if (count == k) return root->val;

        return helper(root->right);
    }
};