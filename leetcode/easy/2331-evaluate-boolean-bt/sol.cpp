/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2331 - Evaluate Boolean Binary Tree
 * @date 16-05-2024
 *
 * Runtime - 12 ms O(n)
 * Memory Usage - 17.33 MB O(log(n)) [Recursive stack]
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
    bool evaluateTree(TreeNode *root) {
        if (root->val == 0) return false;
        if (root->val == 1) return true;

        bool left = evaluateTree(root->left), right = evaluateTree(root->right);

        if (root->val == 2) return left || right;
        return left && right;
    }
};