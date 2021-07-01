/**
 * @file a.cpp
 * @author Vortexx2
 * @brief Problem 682 - Baseball Game
 * @date 01-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 8.3 MB
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isNumber(const string &s)
{
  auto itr = s.begin();
  while (itr != s.end())
  {
    if (isdigit(*itr))
      return true;

    itr++;
  }

  return false;
}

class Solution
{
public:
  int calPoints(vector<string> &ops)
  {
    vector<int> recs;
    int sum = 0;

    for (auto &s : ops)
    {
      int val;
      if (isNumber(s))
      {
        val = stoi(s);
        recs.push_back(val);
      }
      else
      {
        if (s == "+")
        {
          val = recs[recs.size() - 1] + recs[recs.size() - 2];
          recs.push_back(val);
        }

        else if (s == "D")
        {
          val = recs[recs.size() - 1] * 2;
          recs.push_back(val);
        }

        else if (s == "C")
        {
          val = recs[recs.size() - 1] * -1;
          recs.pop_back();
        }
      }

      sum += val;
    }

    return sum;
  }
};