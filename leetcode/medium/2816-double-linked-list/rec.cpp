/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 2816 - Double a Number Represented as a Linked List
 * @date 07-05-2024
 * 
 * Runtime - 159 ms O(n)
 * Memory Usage - 121.04 MB O(n) (recursive stack)
 */
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:

  int carry = 0;
  ListNode* doubleIt(ListNode* head) {
    traverse(head);
    if (!carry) return head;

    ListNode *newHead = new ListNode(1, head);
    return newHead;
  }

  void traverse(ListNode* curr) {
    if (!curr) return;

    traverse(curr->next);
    curr->val = curr->val * 2 + carry;
    if (curr->val > 9) carry = 1;
    else carry = 0;

    curr->val = curr->val % 10;
  }
};