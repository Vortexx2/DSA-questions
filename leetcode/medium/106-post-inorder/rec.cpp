/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 106 - Construct BT From Inorder and Postorder Traversal
 * @date 10-08-2021
 * 
 * Runtime - 12 ms
 * Memory Usage - 26.5 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
  int index;
  unordered_map<int, int> dic;
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    if (postorder.empty())
      return nullptr;
    for (int i = 0; i < inorder.size(); i++)
      dic.insert({inorder[i], i});

    index = inorder.size() - 1;
    return helper(inorder, postorder, 0, inorder.size());
  }

  TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int start, int end)
  {
    if (end - start == 1)
      return new TreeNode(postorder[index]);

    int respectiveIndex = index;
    int i = dic[postorder[index]];

    TreeNode *left = nullptr, *right = nullptr;
    if (end - i > 1) {
      index--;
      right = helper(inorder, postorder, i + 1, end);
    }

    if (i - start > 0) {
      index--;
      left = helper(inorder, postorder, start, i);
    }
    return new TreeNode(postorder[respectiveIndex], left, right);
  }
};