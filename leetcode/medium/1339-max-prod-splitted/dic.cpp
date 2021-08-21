/**
 * @file dic.cpp
 * @author Vortexx2
 * @brief Problem 1339 - Max Product of Splitted BT
 * @approach Initial thought using 2 passes
 * @date 21-08-2021
 * 
 * Runtime Error - Because of integer overflow
 */
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
  int maxProduct(TreeNode *root) {
    unordered_map<TreeNode *, int> sumDic;
    writesumDic(root, sumDic);
    return (max(helper(root, root->left, sumDic),
                helper(root, root->right, sumDic))) %
           ((long long)1e9 + 7);
  }

  long long helper(TreeNode *fNode, TreeNode *sNode,
                  unordered_map<TreeNode *, int> &sumDic) {
    if (!sNode) return 0;

    long long prod = sumDic[sNode] * (sumDic[fNode] - sumDic[sNode]);
    long long childProd = max(helper(fNode, sNode->left, sumDic),
                             helper(fNode, sNode->right, sumDic));

    return max(prod, childProd);
  }

  int writesumDic(TreeNode *root, unordered_map<TreeNode *, int> &sumDic) {
    if (!root) return 0;

    sumDic.insert({root, writesumDic(root->left, sumDic) +
                             writesumDic(root->right, sumDic) + root->val});

    return sumDic[root];
  }
};