/**
 * @file map.cpp
 * @author Vortexx2
 * @brief Problem 109 - Sorted LL to BST
 * @date 24-08-2021
 * 
 * Runtime - 16 ms
 * Memory Usage - 31.3 MB
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> arr;

  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return nullptr;

    int length = lengthOfList(head);
    return construct(head, 0, length);
  }

  TreeNode *construct(ListNode *head, int min, int max) {
    if (min >= max) return nullptr;

    int mid = (min + max) / 2;

    TreeNode *root = new TreeNode(arr[mid]);
    root->left = construct(head, min, mid);
    root->right = construct(head, mid + 1, max);
    return root;
  }

  int lengthOfList(ListNode *head) {
    int length = 0;
    while (head) {
      arr.push_back(head->val);
      length++;
      head = head->next;
    }
    return length;
  }
};