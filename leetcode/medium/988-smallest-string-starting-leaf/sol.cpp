/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 988 - Smallest String starting from Leaf
 * @date 18-04-2024
 *
 * Runtime - 9 ms O(n^2)
 * Memory Usage - 25.5 MB O(n)
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
    // string res;
    string smallestFromLeaf(TreeNode *root) {
        string smallest;
        recSmallest(root, "", smallest);

        return smallest;
    }

    void recSmallest(TreeNode *node, string path, string &smallest) {
        if (!node) return;

        path += string(1, 'a' + node->val);

        if (!node->left && !node->right) {
            reverse(path.begin(), path.end());

            if (smallest.empty() || path < smallest) {
                smallest = path;
            }

            reverse(path.begin(), path.end());
        }

        recSmallest(node->left, path, smallest);
        recSmallest(node->right, path, smallest);
    }
};