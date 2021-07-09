/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 739 - Daily Temperatures
 * Using only the result array to solve the problem
 * Don't know why this is not less space than the stacks approach.
 * @date 08-07-2021
 * 
 * Runtime - 120 ms
 * Memory Usage - 85.1 MB 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    vector<int> res(temperatures.size());
    int j;
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
      j = i + 1;

      while (j < temperatures.size() && temperatures[i] >= temperatures[j])
      {
        if (res[j] > 0)
          j += res[j];
        else
          j = temperatures.size();
      }

      if (j < temperatures.size())
        res[i] = j - i;
    }

    return res;
  }
};