/**
 * @author Vortexx2
 * @brief Problem 236 - LCA of BT
 * 
 * Runtime - 20 ms
 * Memory Usage - 17.8 MB
 */
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    stack<TreeNode *> st;
    unordered_map<TreeNode *, TreeNode *> parents = {{root, nullptr}};
    st.push(root);

    auto itr1 = parents.find(p), itr2 = parents.find(q);
    while (itr1 == parents.end() || itr2 == parents.end())
    {
      TreeNode *node = st.top();
      st.pop();

      if (node->left)
      {
        st.push(node->left);
        parents.insert({node->left, node});
      }
      if (node->right)
      {
        st.push(node->right);
        parents.insert({node->right, node});
      }

      itr1 = parents.find(p), itr2 = parents.find(q);
    }

    unordered_map<TreeNode *, bool> ancestors;
    while (p != nullptr)
    {
      ancestors.insert({p, true});
      p = parents[p];
    }

    auto itr = ancestors.find({q});
    while (itr == ancestors.end())
    {
      q = parents[q];
      itr = ancestors.find({q});
    }

    return q;
  }
};