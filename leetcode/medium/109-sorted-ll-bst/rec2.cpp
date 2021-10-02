/**
 * @file rec2.cpp
 * @author Vortexx2
 * @brief Problem 109 - Convert Sorted LL to BST
 * @date 02-10-2021
 * 
 * Runtime - 47 ms
 * Memory Usage - 30.9 MB
 */
#include <algorithm>
#include <iostream>
#include <utility>

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
  TreeNode *sortedListToBST(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return new TreeNode(head->val);

    ListNode *mid, *p;
    tie(p, mid) = middleNode(head);

    TreeNode *newNode = new TreeNode(mid->val);
    if (p) {
      p->next = nullptr;
      newNode->left = sortedListToBST(head);
    }
    newNode->right = sortedListToBST(mid->next);

    return newNode;
  }

  pair<ListNode *, ListNode *> middleNode(ListNode *head) {
    if (!head) return {nullptr, nullptr};
    ListNode *p = head, *q = head;
    ListNode *prev = nullptr;

    while (q->next && q->next->next) {
      prev = p;
      p = p->next;
      q = q->next->next;
    }

    return {prev, p};
  }
};