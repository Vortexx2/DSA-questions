/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief 
 * @date 13-07-2021
 * 
 * Runtime - 28 ms
 * Memory Usage - 23.8 MB
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
  /**
   * @brief Problem 503 - Next Greater Element II
    @approach Using 2 scans and 1 stack. In 1st scan make sure each closable case is closed
    right on the spot. 2nd spot is for the requirement that the arr is circular.
   * 
   * @param nums 
   * @return vector<int> 
   */
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    stack<int> st;
    vector<int> res(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++)
    {
      while (!st.empty() && nums[i] > nums[st.top()])
      {
        res[st.top()] = nums[i];
        st.pop();
      }

      st.push(i);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (st.empty()) break;

      while (!st.empty() && nums[i] > nums[st.top()])
      {
        res[st.top()] = nums[i];
        st.pop();
      }
    }

    return res;
  }
};