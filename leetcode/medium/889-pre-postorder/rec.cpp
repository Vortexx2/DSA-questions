/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 889 - Construct BT from Preorder and Postorder
 * @date 16-08-2021
 * 
 * Runtime - 8 ms O(n)
 * Memory Usage - 25.5 MB O(h)
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
  int preIndex = 0, postIndex = 0;
  TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
  {
    TreeNode *root = new TreeNode(preorder[preIndex++]);

    if (root->val != postorder[postIndex])
      root->left = constructFromPrePost(preorder, postorder);

    if (root->val != postorder[postIndex])
      root->right = constructFromPrePost(preorder, postorder);

    postIndex++;
    return root;
  }
};