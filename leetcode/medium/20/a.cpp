/**
 * @file a.cpp
 * @author Vortexx2
 * @brief Problem 20 - Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * @date 29-06-2021
 * 
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    unordered_map<char, char> openMap = {
        {'}', '{'},
        {']', '['},
        {')', '('}};

    stack<char> st;

    for (auto &ch : s)
    {

      if (ch == '{' || ch == '(' || ch == '[')
      {
        st.push(ch);
      }
      else
      {
        auto itr = openMap.find(ch);

        if (itr != openMap.end())
        {

          if (st.empty())
            return false;

          if (st.top() == itr->second)
          {
            st.pop();
          }

          else
            return false;
        }
      }
    }

    return st.empty();
  }
};