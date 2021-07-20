/**
 * @file queue.cpp
 * @author Vortexx2
 * @brief Problem 1700 - Number of Students Unable to Eat Lunch
 * @date 20-07-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 8.6 MB
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
  int countStudents(vector<int> &students, vector<int> &sandwiches)
  {
    int i = 0, j = 0;
    queue<int> q;

    while (i < students.size())
    {
      if (j == sandwiches.size())
        return 0;

      if (students[i] == sandwiches[j])
        j++;

      else
        q.push(i);

      i++;
    }

    int count = q.size();
    while (count)
    {

      for (int k = 0; k < count; k++)
      {
        if (students[q.front()] == sandwiches[j])
        {
          j++;
          q.pop();
        }
        else
        {
          q.push(q.front());
          q.pop();
        }
      }

      if (count == q.size())
        return q.size();

      count = q.size();
    }

    return 0;
  }
};