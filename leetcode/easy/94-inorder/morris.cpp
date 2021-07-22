/**
 * @file morris.cpp
 * @author Vortexx2
 * @brief Problem 94 - Binary Tree Inorder Traversal
 * @date 22-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 8.2 MB
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
   * @brief Using the *Morris Traversal Algorithm* to get a solution which is O(n) in time and O(1) in space complexity.
   * 
   * @param root 
   * @return vector<int> 
   */
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> res;

    while (root)
    {
      if (root->left)
      {
        TreeNode *predecessor = findPredecessor(root);
        if (!predecessor->right)
        {
          predecessor->right = root;
          root = root->left;
        }

        else
        {
          predecessor->right = NULL;
          res.push_back(root->val);
          root = root->right;
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

  /**
   * @brief Finds the predecessor for a particular node.
   * 
   * @param node 
   * @return TreeNode* 
   */
  TreeNode *findPredecessor(TreeNode *node)
  {
    TreeNode *curr = node;
    // node->left will exist since we only call method when left exists
    curr = curr->left;

    while (curr->right && curr->right != node)
      curr = curr->right;

    return curr;
  }
};