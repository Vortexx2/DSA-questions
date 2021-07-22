/**
 * @file morris.cpp
 * @author Vortexx2
 * @brief Problem 144 - Binary Tree Preorder Traversal
 * @date 22-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 8.3 MB
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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res;

    while (root)
    {
      if (root->left)
      {
        TreeNode *pred = findPredecessor(root);

        if (pred->right)
        {
          pred->right = NULL;
          root = root->right;
        }
        else
        {
          pred->right = root;
          res.push_back(root->val);
          root = root->left;
        }
      }

      else
      {
        res.push_back(root->val);
        root = root->right;
      }
    }

    return res;
  }

  TreeNode *findPredecessor(TreeNode *node)
  {
    TreeNode *curr = node->left;
    while (curr->right && curr->right != node)
      curr = curr->right;

    return curr;
  }
};