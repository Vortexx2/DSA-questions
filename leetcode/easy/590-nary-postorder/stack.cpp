/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 590 - Nary Postorder Traversal
 * @date 20-08-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 11.2 MB
 */
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<int> postorder(Node *root) {
    if (!root) return {};

    stack<Node *> st;
    vector<int> res;
    st.push(root);

    while (!st.empty()) {
      Node *top = st.top();
      st.pop();
      res.push_back(top->val);

      for (int i = 0; i < top->children.size(); i++)
        st.push(top->children[i]);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};