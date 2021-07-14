/**
 * @file kadane.cpp
 * @author Vortexx2
 * @brief 
 * @date 14-07-2021
 * 
 * Runtime - 0ms 
 * Memory Usage - 13.1 MB
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int maxSum = INT_MIN;
    int currSum = 0;
    int temp = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      temp = currSum + nums[i];

      if (nums[i] > temp)
        currSum = nums[i];

      else
        currSum = temp;

      if (currSum > maxSum)
      {
        maxSum = currSum;
      }
    }

    return maxSum;
  }
};

int main()
{
  cout << INT_MIN << endl;
}
