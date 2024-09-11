#include <bits/stdc++.h>

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

int getGCD(int a, int b) {
    int minNum = min(a, b);
    int maxNum = max(a, b);

    int gcd = 1;

    for (int i = minNum; i >= 1; i--) {
        if (maxNum % i == 0 && minNum % i == 0) {
            gcd = i;
            break;
        }
    }

    return gcd;
}

class Solution {
   public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) return head;

        ListNode *prev = head, *curr = head->next;

        while (curr) {
            int gcd = getGCD(prev->val, curr->val);
            ListNode* newNode = new ListNode(gcd);

            prev->next = newNode;
            newNode->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};