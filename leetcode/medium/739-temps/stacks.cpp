/**
 * @file stacks.cpp
 * @author Vortexx2
 * @brief Problem 739 - Daily Temperatures
 * @date 08-07-2021
 * 
 * Runtime - 204 ms
 * Memory Usage - 85.1 MB
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    if (temperatures.size() == 1)
    {
      temperatures[0] = 0;
      return temperatures;
    }

    stack<int> st;
    vector<int> res(temperatures.size());

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && temperatures[st.top()] <= temperatures[i])
      {
        st.pop();
      }

      if (st.empty())
      {
        res[i] = 0;
      }

      else
      {
        res[i] = st.top() - i;
      }
      st.push(i);
    }

    return res;
  }
};