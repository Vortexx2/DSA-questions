/**
 * @file 2-pointers.cpp
 * @author Vortexx2
 * @brief Problem 82 - Remove Duplicates From Sorted List II
 * @approach Using 2 pointers
 * @date 23-10-2022
 *
 * Runtime - 7 ms O(n)
 * Memory Usage - 11.1 MB O(1)
 */
#include <climits>
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* newHead = new ListNode(INT_MIN);

    ListNode *prev = newHead, *left = head, *right;

    // have we encountered duplicates for the current value
    bool dupes;

    while (left) {
      right = left->next;
      dupes = false;

      while (right && right->val == left->val) {
        dupes = true;
        right = right->next;
      }

      // if we have not encountered duplicates
      if (!dupes) {
        prev->next = left;
        prev = prev->next;
      }

      // if we have, set next to nullptr, for cases when last sequence is
      // duplicates
      else {
        prev->next = nullptr;
      }

      left = right;
    }

    return newHead->next;
  }
};