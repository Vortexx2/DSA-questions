#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prec(char ch)
{
  if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '^')
  {
    return 3;
  }

  // It will only return -1 for '('
  return -1;
}

std::string to_postfix(std::string infix)
{
  stack<char> st;
  string val = "";

  for (auto &ch : infix)
  {
    if (isdigit(ch))
    {
      val += ch;
    }

    else if (ch == '(')
    {
      st.push(ch);
    }

    else if (ch == ')')
    {
      while (st.top() != '(')
      {
        val += st.top();
        st.pop();
      }
      st.pop();
    }

    else
    {
      while (!st.empty() && (prec(ch) <= prec(st.top())))
      {
        val += st.top();
        st.pop();
      }

      st.push(ch);
    }
  }

  while (!st.empty())
  {
    val += st.top();
    st.pop();
  }

  return val;
}

int main()
{
  string s = "1+2+3";

  cout << to_postfix(s) << endl;
}