/**
 * @file two-pointers.cpp
 * @author Vortexx2
 * @brief Problem 19 - Remove Nth Node from End of List
 * @approach Using 2 pointers
 * @date 07-10-2022
 * 
 * Runtime - 3 ms O(n)
 * Memory Usage - 10.7 MB O(1)
 */
#include <iostream>

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *back = head, *front = head;
    ListNode* beforeBack = nullptr;

    int i = 0;
    while (front && i < n) {
      front = front->next;
      i++;
    }

    if (i < n) return head;

    while (front) {
      front = front->next;
      beforeBack = back;
      back = back->next;
    }

    if (back == head) {
      ListNode* newHead = head->next;

      if (!newHead) return nullptr;

      delete head;
      return newHead;
    }

    beforeBack->next = back->next;
    delete back;

    return head;
  }
};