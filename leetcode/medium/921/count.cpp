/**
 * @file stack.cpp
 * @author Vortexx2
 * @brief Problem 921 - Minimum Add To Make Parentheses Valid
 * @approach Arithmetic checks and balances
 * @date 30-06-2021
 * 
 * Runtime - 0ms
 * Memory Usage - 6.1 MB
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
    int bal = 0, count = 0;

    for (auto &ch : s)
    {
      bal += ((ch == '(') ? 1 : -1);

      if (bal == -1)
      {
        bal = 0;
        count += 1;
      }
    }
    return bal + count;
  }
};