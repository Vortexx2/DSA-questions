/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 206 - Reverse a linked list
 * @date 13-10-2022
 * 
 * Runtime - 3 ms O(n)
 * Memory Usage - 8.4 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    ListNode *prev = nullptr, *next = head->next;

    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};