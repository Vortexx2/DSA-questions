/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief 
 * @date 15-07-2021
 * 
 * Runtime - Time Limit Exceeded
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  string removeDuplicates(string s)
  {
    stack<char> st;
    string res = "";

    for (auto &ch : s)
    {
      if (!st.empty() && ch == st.top())
      {
        st.pop();
      }

      else
      {
        st.push(ch);
      }
    }

    while (!st.empty())
    {
      res = st.top() + res;
      st.pop();
    }

    return res;
  }
};