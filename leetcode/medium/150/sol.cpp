/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 150 - Evaluate Reverse Polish Notation 
 * @date 01-07-2021
 * 
 * Runtime - 64 ms
 * Memory Usage - 14.4 MB
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isNumber(const string s)
{
  auto itr = s.begin();
  while (itr != s.end())
  {
    if (isdigit(*itr))
      return true;

    itr++;
  }

  return false;
}

int operate(int a, int b, string token)
{

  if (token == "+")
  {
    return a + b;
  }

  if (token == "-")
  {
    return a - b;
  }

  if (token == "*")
  {
    return a * b;
  }

  if (token == "/")
  {
    return (int)(a / b);
  }

  return (a + b);
}

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;

    for (auto &token : tokens)
    {
      if (isNumber(token))
      {
        st.push(stoi(token));
      }

      else
      {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        int res = operate(b, a, token);
        st.push(res);
      }
    }

    return st.top();
  }
};

int main()
{
  Solution *sol = new Solution();
  vector<string> a = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  // cout << isNumber("-3") << endl;
  sol->evalRPN(a);
}