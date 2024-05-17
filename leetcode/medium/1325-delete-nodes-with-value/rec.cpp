/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 1325 - Delete Nodes With Given Value
 * @date 17-05-2024
 *
 * Runtime - 14 ms O(n)
 * Memory Usage - 21.35 MB O(logn) [recursive stack]
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
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        if (!root) return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (!root->left && !root->right && root->val == target) return nullptr;

        return root;
    }
};