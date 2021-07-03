/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 234 - Palindrome Linked List
 * @approach Using vectors
 * @date 03-07-2021
 * 
 * Runtime - 208 ms
 * Memory Usage - 123.4 MB
 */
#include <iostream>
#include <vector>

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

    vector<int> vec;
    ListNode *curr = head;

    while (curr != nullptr)
    {
      vec.push_back(curr->val);
      curr = curr->next;
    }

    int len = vec.size();

    for (int i = 0; i <= (len / 2); i++)
    {
      if (vec[i] != vec[len - (i + 1)])
        return false;
    }

    return true;
  }
};