/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 116 - Populating Next Right Pointers in Each Node
 * @approach Using a DFS approach
 * @date 06-11-2022
 * 
 * Runtime - 43 ms O(n)
 * Memory Usage - 16.8 MB O(1) (In this question, recursive stack does not count)
 */
#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;

    if (root->left) root->left->next = root->right;

    if (root->right && root->next) root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);

    return root;
  }
};