/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 117 - Populating Next Right Pointers in Each Node
 * @approach Using a DFS approach
 * @date 06-11-2022
 *
 * Runtime - 25 ms O(n)
 * Memory Usage - 17.4 MB O(1) (In this question, recursive stack does not
 * count)
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

    Node* rNext = root->next;

  
    // if left child exists
    if (root->left) {
      // if right child exists, next of left will be right child
      if (root->right) root->left->next = root->right;

      // else
      else {
        while (rNext) {
          if (!rNext->left && !rNext->right) {
            rNext = rNext->next;
            continue;
          }

          if (rNext->left)
            root->left->next = rNext->left;

          else
            root->left->next = rNext->right;

          break;
        }
      }
    }

    if (root->right) {

      while (rNext) {

        if (!rNext->left && !rNext->right) {

          rNext = rNext->next;
          continue;
        }

        if (rNext->left)
          root->right->next = rNext->left;

        else
          root->right->next = rNext->right;
        
        break;
      }
    }

    connect(root->right);
    connect(root->left);


    return root;
  }
};