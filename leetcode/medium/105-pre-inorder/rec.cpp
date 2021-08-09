/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 105 - Construct Binary Tree From Preorder and Inorder
 * @date 10-08-2021
 * 
 * Runtime - 36 ms
 * Memory Usage - 26.1 MB
 */
#include <iostream>
#include <vector>

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
  int index;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    if (!preorder.size())
      return nullptr;
    index = 0;
    return helper(preorder, inorder, 0, preorder.size());
  }

  TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end)
  {
    int respectiveIndex = index;

    if (end - start == 1)
    {
      return new TreeNode(preorder[index]);
    }

    int i = start;
    while (i < end)
    {
      if (inorder[i] == preorder[index])
        break;
      i++;
    }

    TreeNode *left = nullptr, *right = nullptr;
    if (i - start > 0)
    {
      // meaning left subtree exists
      index++;
      left = helper(preorder, inorder, start, i);
    }

    if (end - i > 1)
    {
      // meaning right subtree exists
      index++;
      right = helper(preorder, inorder, i + 1, end);
    }

    return new TreeNode(preorder[respectiveIndex], left, right);
  }
};