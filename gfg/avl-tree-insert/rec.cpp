#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  int height;

  Node(int x) {
    data = x;
    left = right = NULL;
    height = 1;
  }
};

Node* newNode(int data, Node* left = nullptr, Node* right = nullptr) {
  Node* nNode = new Node(data);
  nNode->left = left;
  nNode->right = right;

  nNode->height = 0;
  if (left) nNode->height = left->height;
  if (right) nNode->height = max(nNode->height, right->height);

  return nNode;
}

class Solution {
 public:
  /*You are required to complete this method */
  Node* insertToAVL(Node* node, int data) {
    if (!node) {
      return newNode(data);
    }

    if (data < node->data)
      node->left = insertToAVL(node->left, data);

    else if (data > node->data)
      node->right = insertToAVL(node->right, data);

    else
      return node;  // nodes with equal values are not allowed in BST

    // Update the height of the current node
    // height of the current can change depending on which subtree it is
    // inserted in therefore (1 + node->height is wrong)
    node->height = 1 + max(height(node->left), height(node->right));

    int currBalance = balanceFactor(node);

    // left heavy, perform right rotation with respect to current node
    if (currBalance > 1 && node->left->data > data) return rightRotate(node);

    // right heavy, perform left rotation with respect to current node
    if (currBalance < -1 && data > node->right->data) return leftRotate(node);

    // left heavy (LR), perform left rotation with respect to left node of current node
    // and then right rotation with respect to current node
    if (currBalance > 1 && data > node->left->data) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    // right heavy (RL), perform right rotation with respect to right node of current node
    // and then left rotation with respect to current node
    if (currBalance < -1 && data < node->right->data) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    // if tree is balanced, return node
    return node;
  }

  int height(Node* node) {
    if (!node) return -1;

    return node->height;
  }

  int balanceFactor(Node* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
  }

  Node* rightRotate(Node* node) {
    // node is guaranteed to have a left child due to balance factor being
    // greater than 1
    Node *lef = node->left, *lefRight = lef->right;

    lef->right = node;
    node->left = lefRight;

    // Update heights of modified nodes
    node->height = max(height(node->left), height(node->right)) + 1;
    lef->height = max(height(lef->left), height(lef->right)) + 1;

    return lef;
  }

  Node* leftRotate(Node* node) {
    // node is guaranteed to have a left child to balance factor being lesser
    // than 1
    Node *right = node->right, *rightLeft = right->left;

    right->left = node;
    node->right = rightLeft;

    // Update heights of modified nodes
    node->height = 1 + max(height(node->left), height(node->right));
    right->height = 1 + max(height(right->left), height(right->right));

    return right;
  }
};