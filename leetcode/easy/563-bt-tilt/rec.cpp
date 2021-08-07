/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 563 - BT Tilt
 * @date 07-08-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 23.8 MB
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution
{
public:
  int findTilt(TreeNode *root)
  {
    int tiltSum = 0;
    helper(root, tiltSum);
    return tiltSum;
  }

  int helper(TreeNode *root, int &tiltSum)
  {
    if (!root)
      return 0;

    int left = helper(root->left, tiltSum);
    int right = helper(root->right, tiltSum);
    int diff = abs(left - right);
    tiltSum += diff;

    return left + right + root->val;
  }
};