/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 21 - Merge 2 Sorted Lists
 * @approach Recursive
 * @date 13-10-2022
 * 
 * Runtime - 15 ms O(m + n)
 * Memory Usage - 14.9 MB O(m + n) Stack will use this memory
 */
#include <climits>
#include <iostream>

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

using namespace std;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* newHead = new ListNode(0);

    newHead->next = helper(list1, list2, newHead);

    return newHead->next;
  }

  ListNode* helper(ListNode* p, ListNode* q, ListNode* prevNode) {
    if (!p) return q;
    if (!q) return p;

    if (p->val < q->val) {
      prevNode->next = p;
      ListNode* nxt = p->next;
      p->next = helper(nxt, q, p);

      return p;
    }

    else {
      prevNode->next = q;
      ListNode* nxt = q->next;
      q->next = helper(p, nxt, q);

      return q;
    }
  }
};