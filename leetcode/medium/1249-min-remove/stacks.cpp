/**
 * @file stacks.cpp
 * @author Vortexx2
 * @brief Problem 1249 - Minimum Remove to Make Valid Parentheses
 * @approach Using a stack to store indices of opening tags. Only append to answer string if 
 * stack is empty, meaning only if there are no open ( present.
 * @date 05-07-2021
 * 
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    if (s == "")
      return "";

    stack<int> st; // to store indexes of open parentheses
    string res = "";

    // go through given string once
    // append each letter, but do something specific for '(' and ')'
    for (int i = 0; i < s.size(); i++)
    {
      // keep track of indices of the open parentheses by pushing size of `res` before
      // also appending current character to `res`
      if (s[i] == '(')
      {
        st.push(res.size());
      }

      else if (s[i] == ')')
      {
        // if stack is empty, don't append ')' at all
        if (st.empty())
          continue;

        st.pop();
      }

      res += s[i];
    }

    if (st.empty())
      return res;

    // we need to go in a reverse order in the string so that deletion causing the string to
    // get smaller doesn't affect the indices
    // Therefore, stacks are used
    while (!st.empty())
    {
      res.erase(res.begin() + st.top());
      st.pop();
    }

    return res;
  }
};
