#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief Iterating over the first `n` natural numbers, return the string of Push and Pop
   * operations that form the `target` array.
   * 
   * @param target 
   * @param n 
   * @return vector<string> 
   */
  vector<string> buildArray(vector<int> &target, int n)
  {
    int i = 0;
    vector<string> res;
    for (int j = 1; j <= n; j++)
    {
      if (target[i] == j)
      {
        res.push_back("Push");

        i++;
        if (i >= target.size())
          break;
      }

      else
      {
        res.push_back("Push");
        res.push_back("Pop");
      }
    }

    return res;
  }
};