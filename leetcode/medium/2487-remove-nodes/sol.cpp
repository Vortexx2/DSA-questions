/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2487 - Remove Nodes from Linked List
 * @date 06-05-2024
 *
 * Runtime - 267 ms O(n)
 * Memory Usage - 164.9 MB O(n) [rec stack]
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
    ListNode* maxNode;
    ListNode* removeNodes(ListNode* head) {
        maxNode = nullptr;

        rec(head);
        return maxNode;
    }

    void rec(ListNode* curr) {
        if (curr->next) rec(curr->next);

        if (!maxNode || curr->val >= maxNode->val) {
            curr->next = maxNode;
            maxNode = curr;
        }
    }
};