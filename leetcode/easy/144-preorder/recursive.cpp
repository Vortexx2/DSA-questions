/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 144 - Binary Tree Preorder Traversal
 * @date 20-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 10.5 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
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
  /**
   * @brief Using a stack to store addresses of previous nodes where tree branched.
   * 
   * @param root 
   * @return vector<int> 
   */
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res;

    return helper(root, res);
  }

  vector<int> helper(TreeNode *root, vector<int> &arr)
  {
    if (root)
    {
      arr.push_back(root->val);
      helper(root->left, arr);
      helper(root->right, arr);
    }

    return arr;
  }
};