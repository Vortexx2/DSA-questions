/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 116 - Populating Next Right Pointers In Each Node
 * @approach Using iterative level order traversal
 * @date 10-10-2022
 *
 * Runtime - 24 ms O(n)
 * Memory Usage - 17.5 MB O(n) -> since height of tree is log(n), so number of
 * nodes in last level will be 2 ^ log(n) = n
 */
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>

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
    if (!root) return nullptr;

    vector<Node*> currLevel, nextLevel;
    currLevel.push_back(root);

    while (!currLevel.empty()) {
      for (int i = 0; i < currLevel.size(); i++) {
        Node* node = currLevel[i];

        if (i != currLevel.size() - 1) node->next = currLevel[i + 1];
        if (node->left) nextLevel.push_back(node->left);
        if (node->right) nextLevel.push_back(node->right);
      }

      currLevel = nextLevel;
      nextLevel = {};
    }

    return root;
  }
};