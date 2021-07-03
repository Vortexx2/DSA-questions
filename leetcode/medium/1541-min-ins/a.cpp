/**
 * @file a.cpp
 * @author Vortexx2
 * @brief Problem 1541 - Minimum Insertions to balance a parentheses string
 * @approach - Shit. Don't use this.
 * @date 03-07-2021
 * 
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int minInsertions(string s)
  {
    if (s.empty())
      return 0;

    stack<char> st;
    int count = 0;
    auto itr = s.begin();

    while (itr != s.end())
    {

      if (*itr == '(')
      {
        st.push('(');
        itr++;
      }
      else
      {
        if (*(itr + 1) == ')')
        {
          if (st.empty())
          {
            count++;
          }
          else
          {
            st.pop();
          }

          itr += 2;
        }

        else if (*(itr + 1) == '(')
        {
          if (st.empty())
          {
            count += 2;
          }
          else
          {
            st.pop();
            count++;
          }

          itr++;
        }

        else
        {
          if (st.empty())
          {
            count += 2;
          }

          else
          {
            count++;
            st.pop();
          }

          itr++;
        }
      }
    }

    return count + (2 * st.size());
  }
};

int main()
{
  Solution sol = Solution();

  cout << sol.minInsertions("())") << endl;
}