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
  ListNode *current = head;
  ListNode *prev = NULL, *next = NULL;

  while (current != NULL)
  {
    // Store next
    next = current->next;

    // Reverse current ListNode's pointer
    current->next = prev;

    // Move pointers one position ahead.
    prev = current;
    current = next;
  }

  return prev;
}

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr)
      return true;

    int len = 0;
    ListNode *curr = head;

    while (curr != nullptr)
    {
      len++;
      curr = curr->next;
    }

    int middle = len / 2;

    len = 0;
    curr = head;

    while (len != (middle - 1))
    {
      curr = curr->next;
      len++;
    }

    ListNode *temp = curr->next;
    curr->next = nullptr;

    temp = reverse(temp);
    curr = head;

    while (curr != nullptr)
    {
      if (curr->val != temp->val)
      {
        return false;
      }

      curr = curr->next;
      temp = temp->next;
    }

    return true;
  }
};