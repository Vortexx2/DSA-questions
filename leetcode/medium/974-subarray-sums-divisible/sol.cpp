/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 974 - Subarray Sums Divisible by k
 * @date 19-01-2023
 * 
 * Runtime - 67 ms O(n)
 * Memory Usage - 31.7 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

int remainder(int a, int b) { return (b + (a % b)) % b; }

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remCounter;
    int currSum = 0;
    int currRem;

    int res = 0;

    for (auto& num : nums) {
      currSum += num;
      currRem = remainder(currSum, k);

      if (remCounter.find(currRem) == remCounter.end())
        remCounter[currRem] = 0;

      else
        remCounter[currRem]++;

      if (!currRem) res++;
      res += remCounter[currRem];
    }

    return res;
  }
};
