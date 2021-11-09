#include <iostream>
#include <vector>

using namespace std;

// Structure of node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

class Solution {
 public:
  bool isHeap(struct Node *tree) {
    if (!tree) return true;

    if (!isComplete(tree)) return false;

    return isMaxHeap(tree);
  }

  /**
   * @brief Checks if given tree is a valid max heap tree, given that it is
   * complete
   *
   * @param node Root of given subtree
   * @return true if it is a valid max heap tree
   */
  bool isMaxHeap(struct Node *node) {
    if (!node) return true;

    if (nodeVal(node) > nodeVal(node->left) &&
        nodeVal(node) > nodeVal(node->right)) {
      return (isMaxHeap(node->left) && isMaxHeap(node->right));
    }

    return false;
  }

  int nodeVal(Node *node) {
    if (!node) return 0;

    return node->data;
  }

  /**
   * @brief Level order traversal approach to find out completeness of binary
   * tree
   *
   * @param root: root of tree
   * @return true if tree is almost complete
   * @return false
   */
  bool isComplete(Node *root) {
    if (!root) return true;

    vector<Node *> level = {root};
    // has to be declared in the most outter scope possible, if it ever turns
    // true and we encounter another child, we know tree is not balanced
    bool prevNotComplete = false;

    while (!level.empty()) {
      vector<Node *> nextLevel;

      for (Node *&node : level) {
        // node has right child but not left child
        if (!node->left && node->right) return false;

        // if any of previous nodes missed a child, but current node has a
        // child, not complete
        if (prevNotComplete && (node->left || node->right)) return false;

        if (node->left)
          nextLevel.push_back(node->left);
        else
          prevNotComplete = true;

        if (node->right)
          nextLevel.push_back(node->right);
        else
          prevNotComplete = true;
      }

      level = nextLevel;
    }

    return true;
  }
};
