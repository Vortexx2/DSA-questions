/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 740 - Delete and Earn
 * @approach Used a custom DP approach
 * @date 30-06-2022
 *
 * Runtime - 20 ms
 * Memory Usage - 13 MB
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<int, int> counterDic;

  /**
   * @brief First, builds a counterDic which maps (element, count).
   * Second, builds a sorted vector `newVec` with only unique values existing in
   * original `nums`. Third, iterates through `newVec` to get the answer, by
   * dividing problem into subproblems.
   *
   * @param nums
   * @return int
   */
  int deleteAndEarn(vector<int>& nums) {
    // counter for each element
    populateMap(nums);

    // sorted vector of unique elements in `nums`
    vector<int> newVec;
    populateVector(newVec);

    int n = newVec.size();
    if (n == 1) return newVec[0] * counterDic[newVec[0]];

    int a = newVec[0] * counterDic[newVec[0]],
        b = findSecond(newVec[0], newVec[1]);

    int res = b;
    for (int i = 2; i < n; i++) {
      // if difference between current and previous element is 1, we can only
      // select previous max value or ( prev. prev. max value + curr. value )
      if (newVec[i] - newVec[i - 1] == 1)
        res = max(b, newVec[i] * counterDic[newVec[i]] + a);

      // if difference is not 1, we can select both the previous subproblem
      // solution and the current element
      else
        res = b + (newVec[i] * counterDic[newVec[i]]);

      a = b;
      b = res;
    }

    return res;
  }

  /**
   * @brief Builds a counter for each element. Since a map is used, the elements
   * are in order when iterating through them.
   *
   * @param nums
   */
  void populateMap(vector<int>& nums) {
    for (auto const num : nums) counterDic[num]++;
  }

  /**
   * @brief Using iterators through the `counterDic`, elements can be traversed
   * in a sorted order. Build a vector of unique values.
   *
   * @param newVec
   */
  void populateVector(vector<int>& newVec) {
    for (auto i = counterDic.begin(); i != counterDic.end(); i++)
      newVec.push_back(i->first);
  }

  /**
   * @brief finds the solution to the second subproblem when going from left to
   * right in the sequence.
   *
   * @param firstElem
   * @param secondElem
   * @return int
   */
  int findSecond(int firstElem, int secondElem) {
    if (secondElem - 1 == firstElem)
      return max(counterDic[firstElem] * firstElem,
                 counterDic[secondElem] * secondElem);

    return counterDic[firstElem] * firstElem +
           counterDic[secondElem] * secondElem;
  }
};