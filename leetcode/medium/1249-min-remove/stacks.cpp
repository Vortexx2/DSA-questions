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

    for (int i = 0; i < s.size(); i++)
    {

      if (s[i] == '(')
      {
        st.push(res.size());
      }

      else if (s[i] == ')')
      {
        if (st.empty())
          continue;

        st.pop();
      }

      res += s[i];
    }

    if (st.empty())
      return res;

    while (!st.empty())
    {
      res.erase(res.begin() + st.top());
      st.pop();
    }

    return res;
  }
};
