/**
 * @file greedy.cpp
 * @author Vortexx2
 * @brief Problem 45 - Jump Game 2
 * @approach Greedy algorithm (https://www.youtube.com/watch?v=dJ7sWiOoK7g)
 * @date 01-07-2022
 *
 * Runtime - 22 ms O(n)
 * Memory Usage - 16.6 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();

    // guaranteed to get to goal
    if (n <= 2) return (n - 1);

    // interval is the range of positions that we can get from the current
    // position
    pair<int, int> interval = {0, 0};
    // current number of jumps
    int jumps = 0;

    while (true) {
      // if the interval where we can be encapsulates our goal, we've reached
      if (interval.second >= n - 1) return jumps;
      // each expansion of the next interval means we can get to any position in
      // that interval with one jump
      jumps++;

      // max position we can reach from the current position
      int canReach = -1;

      // go through each value of the interval and figure out the next interval
      for (int i = interval.first; i <= interval.second; i++) {
        canReach = max(canReach, i + nums[i]);
      }

      interval = {interval.second + 1, canReach};
    }
  }
};