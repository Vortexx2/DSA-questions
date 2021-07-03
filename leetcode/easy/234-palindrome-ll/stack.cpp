/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 234 - Palindrome Linked List
 * @approach Using stacks
 * @date 03-07-2021
 * 
 * Runtime - 208 ms
 * Memory Usage - 123.4 MB
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

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr)
      return true;

    ListNode *curr = head;
    stack<int> st;

    while (curr != nullptr)
    {
      st.push(curr->val);
      curr = curr->next;
    }

    curr = head;

    while (curr != nullptr)
    {
      if (st.top() != curr->val)
      {
        return false;
      }

      curr = curr->next;
      st.pop();
    }

    return true;
  }
};