/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 206 - Reverse a Linked List
 * @approach Recursive
 * @date 13-10-2022
 * 
 * Runtime - 15 ms O(n)
 * Memory Usage - 10.5 MB O(n) Stack
 */
#include <iostream>
#include <tuple>
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
    if (!head || !head->next) {
      return head;
    }

    return helper(head).first;
  }

  // recursive function that returns the new head, along with the last node in
  // the sub-linked list
  pair<ListNode *, ListNode *> helper(ListNode *curr) {
    if (!curr->next) return {curr, curr};

    ListNode *lastNode, *newHead;

    tie(newHead, lastNode) = helper(curr->next);

    lastNode->next = curr;
    curr->next = nullptr;
    return {newHead, curr};
  }
};