/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 1014 - Best Sightseeing Pair
 * @approach Simple DP iterative approach by maximising components of the
 * expression
 * @date 09-07-2022
 *
 * Runtime - 69 ms
 * Memory Usage - 39.3 MB
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();

    if (n == 2) return values[0] + values[1] - 1;

    // we need to maximise (val[i] +i) + (val[j] - j)
    int maxScore = values[0];
    int maxA = values[0];  // a = val[i] + i

    for (int i = 1; i < n; i++) {
      maxScore = max(maxScore, maxA + values[i] - i);
      maxA = max(maxA, values[i] + i);
    }

    return maxScore;
  }
};