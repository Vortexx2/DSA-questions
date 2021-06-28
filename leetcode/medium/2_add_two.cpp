#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Question :
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr && l2 == nullptr)
      return nullptr;

    ListNode *preHead = new ListNode(0), *prev = preHead;
    int carry = 0;

    while (l1 || l2 || carry)
    {
      int sum = (l1 ? l1->val : 0);
      sum += (l2 ? l2->val : 0);
      sum += carry;

      ListNode *newNode = new ListNode(sum % 10);
      prev->next = newNode;
      prev = prev->next;

      carry = sum / 10;

      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }

    return preHead->next;
  }
};