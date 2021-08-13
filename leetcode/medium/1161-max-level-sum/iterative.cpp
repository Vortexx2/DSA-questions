/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 1161 - Maximum Level Sum of a BT
 * @date 13-08-2021
 * 
 * Runtime - 176 ms
 * Memory Usage - 113.2 MB
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    vector<TreeNode *> level = {root};
    int maxSum = INT_MIN;
    int maxLevel = 1;
    int i = 1;

    while (!level.empty())
    {
      int currSum = 0;
      vector<TreeNode *> nextLevel;

      for (auto &node : level)
      {
        currSum += node->val;

        if (node->left)
          nextLevel.push_back(node->left);
        if (node->right)
          nextLevel.push_back(node->right);
      }

      if (currSum > maxSum)
      {
        maxSum = currSum;
        maxLevel = i;
      }

      level = nextLevel;
      i++;
    }

    return maxLevel;
  }
};