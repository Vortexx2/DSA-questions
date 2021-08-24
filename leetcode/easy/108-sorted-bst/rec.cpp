/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 108 - Construct Sorted Array into BST
 * @date 24-08-2021
 * 
 * Runtime - 8 ms O(n)
 * Memory Usage - 21.4 MB O(n)
 */
#include <iostream>
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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int length = nums.size();
    int min = 0, max = nums.size();

    return construct(min, max, nums);
  }

  TreeNode *construct(int min, int max, vector<int> &nums) {
    if (min >= max) return nullptr;

    int mid = (min + max) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = construct(min, mid, nums);
    root->right = construct(mid + 1, max, nums);
    return root;
  }
};