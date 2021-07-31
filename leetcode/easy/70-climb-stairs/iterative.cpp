/**
 * @file iterative.cpp
 * @author Vortexx2
 * @brief Problem 70
 * @date 31-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 5.9 MB
 */



class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 3)
      return n;
    int a = 1, b = 2;
    int res;

    for (int i = 2; i < n; i++)
    {
      res = a + b;
      a = b;
      b = res;
    }
  }
};