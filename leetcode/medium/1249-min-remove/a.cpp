/**
 * @file a.cpp
 * @author Vortexx2
 * @brief Problem 1249 - Minimum Remove to Make Valid Parentheses
 * @approach Scanning string twice. Once forward and then backwards.
 * @date 05-07-2021
 * 
 * TLE. Don't know why. O(n).
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

    int count = 0;
    string temp = "";

    for (auto &ch : s)
    {
      if (ch == '(')
      {
        count++;
      }
      else if (ch == ')')
      {
        if (!count)
          continue;

        count--;
      }
      temp += ch;
    }

    count = 0;
    string res = "";

    for (int j = temp.size() - 1; j >= 0; j--)
    {

      if (temp[j] == ')')
      {
        count++;
      }

      else if (temp[j] == '(')
      {
        if (!count)
          continue;

        count--;
      }

      res = temp[j] + res;
    }

    return res;
  }
};