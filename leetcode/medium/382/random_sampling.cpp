/**
 * @file random_sampling.cpp
 * @author Vortexx2
 * @brief Problem 382 - Linked List Random Node
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being chosen.
 * Runtime - 16 ms
 * Memory Usage - 16.6 MB 
 * @date 29-06-2021
 * 
 */
#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Given a singly linked list, return a random node's value from the linked list.
// Each node must have the same probability of being chosen.

class Solution
{
public:
  ListNode *header;
  /** @param head The linked list's head.
  Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode *head)
  {
    header = head;
  }

  /** Returns a random node's value. */
  int getRandom()
  {
    ListNode *curr = header->next;
    int i = 2;
    int val = header->val;

    while (curr != nullptr)
    {
      // Only change `val`, if random value between 0 and 1 is lesser than (1 / i)
      if (((float)rand() / RAND_MAX) < (1 / (float)i))
      {
        val = curr->val;
      }

      curr = curr->next;
      i++;
    }

    return val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
