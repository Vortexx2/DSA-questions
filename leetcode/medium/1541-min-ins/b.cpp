#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int minInsertions(string s)
  {
    int rights = 0, ans = 0;

    for (auto &ch : s)
    {
      if (ch == '(')
      {
        rights += 2;

        if (rights % 2 == 1)
        {
          ans++;
          rights--;
        }
      }

      else if (ch == ')')
      {
        if (!rights)
        {
          ans++;
          rights++;
        }
        else
        {
          rights--;
        }
      }
    }

    return ans + rights;
  }
};