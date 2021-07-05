/**
 * @file once.cpp
 * @author Vortexx2
 * @brief Iterating through string from the beginning and front simultaneously
 * @date 05-07-2021
 * 
 * Runtime - 8 ms
 * Memory - 7.3 MB
 */
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while(!isalnum(s[i]) && i < j) i++;
      while (!isalnum(s[j]) && i < j) j--;
      if (toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
  }
};