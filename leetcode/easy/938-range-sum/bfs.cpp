#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

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
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root) return 0;

    int total = 0;
    vector<TreeNode *> currLevel = {root};

    while (!currLevel.empty()) {
      vector<TreeNode *> nextLevel;
      for (auto &node : currLevel) {
        if (node->val > high) {
          if (node->left) nextLevel.push_back(node->left);
        } else if (node->val < low) {
          if (node->right) nextLevel.push_back(node->right);
        } else {
          total += node->val;
          if (node->left) nextLevel.push_back(node->left);
          if (node->right) nextLevel.push_back(node->right);
        }
      }

      currLevel = nextLevel;
    }

    return total;
  }
};