/**
 * @file level-order.cpp
 * @author Vortexx2
 * @brief Problem 117 - Populating Next Right Pointers In Each Node ii
 * @approach Using a level order approach
 * @date 06-11-2022
 * 
 * Runtime - 7 ms O(n)
 * Memory Usage - 17.9 MB O(1)
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

    vector<Node*> currLevel = {root}, nextLevel;

    Node* prevNode = nullptr;

    while (!currLevel.empty()) {
      prevNode = nullptr;
      for (auto& node : currLevel) {
        if (prevNode) prevNode->next = node;

        if (node->left) nextLevel.push_back(node->left);
        if (node->right) nextLevel.push_back(node->right);

        prevNode = node;
      }

      currLevel = nextLevel;
      nextLevel = {};
    }

    return root;
  }
};