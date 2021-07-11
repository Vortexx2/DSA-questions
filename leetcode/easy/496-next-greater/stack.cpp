/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 496 - Next Greatest Element I
 * @approach Going through `nums2` once to be able to add next greatest element for each element
 * to `umap`.
 * @date 10-07-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 8.8 MB
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  /**
   * @brief Problem 496 - Next Greatest Element 1.
   * Going through `nums2` once to be able to add next greatest element for each element
   * to `umap`.
   * 
   * @param nums1 
   * @param nums2 
   * @return vector<int> 
   */
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> umap;
    stack<int> st;
    vector<int> res(nums1.size(), -1);

    for (int &num : nums2)
    {
      while (!st.empty() && num > st.top())
      {
        umap[st.top()] = num;
        st.pop();
      }
      st.push(num);
    }

    for (int i = 0; i < nums1.size(); i++) {
      auto itr = umap.find(nums1[i]);

      if (itr != umap.end()) {
        res[i] = itr->second;
      }
    }

    return res;
  }
};