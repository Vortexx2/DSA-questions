#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

class Solution {
 public:
  // Function to construct binary tree from parent array.
  Node* createTree(int parent[], int N) {
    vector<Node*> arr(N, nullptr);
    Node* root;

    for (int i = 0; i < N; i++) {
      // if node was already created
      if (arr[i]) {
        if (parent[i] == -1) root = arr[i];
        continue;
      }

      // if node is not created
      arr[i] = new Node(i);

      // if current node is root
      if (parent[i] == -1) {
        root = arr[i];
        continue;
      }

      int curr = parent[i], prev = i;
      while (curr != -1 && !arr[curr]) {
        arr[curr] = new Node(curr);

        arr[curr]->left = arr[prev];
        prev = curr;
        curr = parent[curr];
      }

      if (curr == -1) continue;

      if (arr[curr]->left)
        arr[curr]->right = arr[prev];

      else
        arr[curr]->left = arr[prev];
    }

    return root;
  }
};