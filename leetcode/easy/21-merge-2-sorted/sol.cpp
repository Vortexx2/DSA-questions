/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 21 - Merge 2 Sorted Lists
 * @date 13-10-2022
 * 
 * Runtime - 12 ms O(m + n)
 * Memory Usage - 14.7 MB O(1)
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

    ListNode *p = list1, *q = list2;

    ListNode* newHead = new ListNode(0);
    ListNode* prevNode = newHead;

    while (p || q) {
      if (p && !q) {
        prevNode->next = p;
        p = p->next;
      } else if (!p && q) {
        prevNode->next = q;
        q = q->next;
      }

      else {
        if (p->val < q->val) {
          prevNode->next = p;
          p = p->next;
        }

        else {
          prevNode->next = q;
          q = q->next;
        }
      }

      prevNode = prevNode->next;
    }

    return newHead->next;
  }
};