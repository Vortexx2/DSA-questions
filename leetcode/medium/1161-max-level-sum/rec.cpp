/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 1161 - Maximum Level Sum
 * @date 13-08-2021
 * 
 * Runtime - 156 ms
 * Memory Usage - 104.8 MB
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
    vector<int> levelSum;
    helper(root, 0, levelSum);

    int maxSum = INT_MIN;
    int maxLevel = 1;
    for (int i = 0; i < levelSum.size(); i++)
    {
      if (levelSum[i] > maxSum)
      {
        maxSum = levelSum[i];
        maxLevel = i + 1;
      }
    }

    return maxLevel;
  }

  void helper(TreeNode *root, int level, vector<int> &levelSum)
  {
    if (!root)
      return;
    if (level >= levelSum.size())
      levelSum.push_back(root->val);

    else
      levelSum[level] += root->val;

    helper(root->left, level + 1, levelSum);
    helper(root->right, level + 1, levelSum);
  }
};