/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 921 - Minimum Add To Make Parentheses Valid
 * @approach Using a stack to keep track of opened parentheses.
 * @date 30-06-2021
 * 
 * Runtime - 0ms
 * Memory Usage - 6.4 MB
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    stack<char> st;
    int count = 0;

    for (auto &ch : s)
    {
      if (ch == '(')
      {
        st.push(ch);
      }
      else
      {
        if (st.empty())
        {
          count++;
        }
        else
        {
          st.pop();
        }
      }
    }

    count += st.size();

    return count;
  }
};