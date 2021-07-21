/**
 * @file recursive.cpp
 * @author Vortexx2
 * @brief Problem 589 - N-ary Preorder Traversal
 * @date 20-07-2021
 * 
 * Runtime - 24 ms
 * Memory Usage - 10.9 MB
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

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<int> preorder(Node *root)
  {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
      Node *top = st.top();
      res.push_back(top->val);
      st.pop();

      // Push all children into the stack in reverse order
      for (int i = top->children.size() - 1; i >= 0; i--)
        st.push(top->children[i]);
    }

    return res;
  }
};