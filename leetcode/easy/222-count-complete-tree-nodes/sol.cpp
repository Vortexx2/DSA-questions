/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 222 - Count Complete Tree Nodes
 * 
 * Runtime - 25 ms O(log n)
 * Memory Usage - 29 ms O(log n)
 * @date 2024-08-26
 */
#include <bits/stdc++.h>

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
    int countNodes(TreeNode *root) {
        if (!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;

        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int getRightHeight(TreeNode *node) {
        if (!node) return 0;

        return getRightHeight(node->right) + 1;
    }

    int getLeftHeight(TreeNode *node) {
        if (!node) return 0;

        return getLeftHeight(node->left) + 1;
    }
};