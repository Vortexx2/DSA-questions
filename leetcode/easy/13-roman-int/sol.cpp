/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief 
 * @date 15-07-2021
 * 
 * Runtime - 16 ms
 * Memory Usage - 11 MB
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
    int ptr = -1;
    string res = "";

    int i = 0;
    while (i < s.size())
    {
      if (ptr == -1 || s[i] != res[ptr])
      {
        ptr++;
        res.push_back(s[i]);
        i++;
      }

      else
      {
        while (i < s.size() && ptr != -1 && res[ptr] == s[i])
        {
          i++;
          ptr--;
          res.pop_back();
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution sol = Solution();
  cout << sol.removeDuplicates("abcc") << endl;
}