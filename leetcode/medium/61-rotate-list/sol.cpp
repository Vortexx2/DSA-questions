/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 61 - Rotate List
 * @approach Using a two pointers approach
 * @date 14-05-2023
 * 
 * Runtime - 7 ms O(n)
 * Memory Usage - 11.6 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int countNodes(ListNode* head) {
    int i = 0;
    while (head) {
      head = head->next;
      i++;
    }

    return i;
  }

  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;

    int numNodes = countNodes(head);

    ListNode *ahead = head, *curr = head;

    k = k % numNodes;

    for (int i = 0; i < k; i++) {
      ahead = ahead->next;
      if (!ahead) ahead = head;
    }

    if (ahead == head) return head;

    while (ahead->next) {
      ahead = ahead->next;
      curr = curr->next;
    }

    ListNode* newHead = curr->next;
    curr->next = nullptr;
    ahead->next = head;

    return newHead;
  }
};