/**
 * @file bfs.cpp
 * @author Vortexx2
 * @brief Problem 116 - Populating Next Right Pointer in Each Node
 * @approach Using a BFS approach by using a queue
 * @date 10-10-2022
 * 
 * Runtime - 35 ms O(n)
 * Memory Usage - 17.2 MB O(n)
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

    queue<Node*> q;
    q.push(root);
    Node* currNode;

    while (!q.empty()) {
      Node* prevNode = nullptr;
      for (int i = q.size(); i > 0; i--) {
        currNode = q.front();
        q.pop();

        currNode->next = prevNode;

        if (currNode->left) {
          q.push(currNode->right);
          q.push(currNode->left);
        }

        prevNode = currNode;
      }
    }

    return root;
  }
};