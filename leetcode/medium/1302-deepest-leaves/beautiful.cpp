/**
 * @file beautiful.cpp
 * @author Vortexx2
 * @brief Problem 1302 - Deepest Leaves Sum
 * @date 07-08-2021
 * 
 * Runtime - 28 ms
 * Memory Usage - 40.1 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <string>

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
  int deepestLeavesSum(TreeNode *root)
  {
    if (!root) return 0;

    vector<TreeNode *> level = {root};

    int currSum = 0;
    while (!level.empty())
    {
      currSum = 0;
      vector<TreeNode *> nextLevel;

      for (auto &node: level) {
        currSum += node->val;
        if (node->left) nextLevel.push_back(node->left);
        if(node->right) nextLevel.push_back(node->right);
      }

      level = nextLevel;
    }

    return currSum;
  }
};