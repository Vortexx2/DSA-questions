/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 109 - Sorted LL to BST
 * @date 24-08-2021
 *
 * Runtime - 368 ms
 * Memory Usage - 31 MB
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return nullptr;

    int length = lengthOfList(head);
    return construct(head, 0, length);
  }

  TreeNode *construct(ListNode *head, int min, int max) {
    if (min >= max) return nullptr;

    int mid = (min + max) / 2;
    int i = 0;
    ListNode *curr = head;
    while (i < mid) {
      i++;
      curr = curr->next;
    }

    TreeNode *root = new TreeNode(curr->val);
    root->left = construct(head, min, i);
    root->right = construct(head, i + 1, max);
    return root;
  }

  int lengthOfList(ListNode *head) {
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    return length;
  }
};