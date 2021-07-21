/**
 * @file recursive.cpp
 * @author Vortexx2
 * @brief Problem 589 - N-ary Preorder Traversal
 * @date 20-07-2021
 * 
 * Runtime - 20 ms
 * Memory Usage - 11.3 MB
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
    helper(root, res);

    return res;
  }

  void helper(Node *root, vector<int> &arr)
  {
    if (root)
    {
      arr.push_back(root->val);
      for (auto &child : root->children)
      {
        helper(child, arr);
      }
    }
  }
};