/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 92 - Reverse Linked List 2
 * @approach Using one pass
 * @date 25-05-2023
 * 
 * Runtime - 3 ms O(N)
 * Memory Usage - 7.4 MB O(1)
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head->next) return head;

    if (left == right) return head;

    ListNode *prev = nullptr, *curr = head, *nxt = head->next;
    int i = 1;
    while (i < left) {
      prev = curr;
      curr = nxt;
      nxt = nxt->next;
      i++;
    }

    ListNode *beforeSeq = prev,  // node before sequence that we have to reverse
        *wasFirst = curr;        // node that was first in the subsequence

    while (i <= right) {
      curr->next = prev;
      prev = curr;
      curr = nxt;

      if (nxt) nxt = nxt->next;
      i++;
    }

    if (beforeSeq) beforeSeq->next = prev;

    wasFirst->next = curr;

    return left != 1 ? head : prev;
  }
};