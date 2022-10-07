/**
 * @file two-pointers.cpp
 * @author Vortexx2
 * @brief Problem 876 - Middle of the Linked List
 * @approach Using 2 pointers
 * @date 07-10-2022
 * 
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.1 MB O(1)
 */
#include <iostream>
#include <vector>

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
  ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};