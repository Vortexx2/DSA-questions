/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief 
 * @date 13-07-2021
 * 
 * Runtime - 0ms
 * Memory Usage - 8.4 MB
 */
#include <iostream>
#include <vector>
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
  int maxAscendingSum(vector<int> &nums)
  {
    int currSum = 0, maxSum = -1, lastEl = 0;

    for (auto &n : nums)
    {
      if (n <= lastEl)
      {
        if (currSum > maxSum) {
          maxSum = currSum;
        }
        currSum = 0;
      }

      currSum += n;
      lastEl = n;
    }

    maxSum = max(maxSum, currSum);

    return maxSum;
  }
};

int main()
{
  Solution sol = Solution();
  vector<int> test = {10,
                      20,
                      30,
                      5,
                      10,
                      50};

  cout << sol.maxAscendingSum(test) << endl;
}