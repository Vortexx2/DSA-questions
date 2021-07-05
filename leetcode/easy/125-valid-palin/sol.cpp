/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 125 - Valid Palindromes
 * @approach 2 iterations through the string. Once to rectify non-alphanumeric characters.
 * Second to check if modified string is a palindrome.
 * @date 05-07-2021
 * 
 * Runtime - 8 ms
 * Memory Usage - 7.6 MB
 */
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    string temp = "";

    for (auto &ch : s)
    {
      if (isalnum(ch))
      {
        temp += toupper(ch);
      }
    }

    float mid = temp.size() / 2;
    int i = 0;
    int soze = temp.size();

    while (i < mid)
    {
      if (temp[i] != temp[soze - (i + 1)])
      {
        return false;
      }
      i++;
    }

    return true;
  }
};