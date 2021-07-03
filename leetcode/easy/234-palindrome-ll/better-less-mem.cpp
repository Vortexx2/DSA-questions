/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 234 - Palindrome Linked List
 * @approach Go through once to get length. Second iteration to find middle element.
 * Reverse after middle element. Then compare element by element
 * @date 03-07-2021
 * 
 * Runtime - 180 ms
 * Memory Usage - 113.9 MB
 */
#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head)
{
  // Initialize current, previous and
  // next pointers
  ListNode *prev = NULL, *next = NULL;

  while (head != NULL)
  {
    // Store next
    next = head->next;

    // Reverse head ListNode's pointer
    head->next = prev;

    // Move pointers one position ahead.
    prev = head;
    head = next;
  }

  return prev;
}

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return true;

    ListNode *slow = head, *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    while (slow != nullptr)
    {
      if (head->val != slow->val)
      {
        return false;
      }

      slow = slow->next;
      head = head->next;
    }

    return true;
  }
};