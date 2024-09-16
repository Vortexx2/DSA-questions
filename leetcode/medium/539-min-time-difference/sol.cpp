/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 539 - Minimum Time Difference
 * 
 * Runtime - 7 ms O(n log n)
 * Memory Usage - 17.5 MB O(n)
 * @date 2024-09-16
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> times(n, 0);
        for (int i = 0; i < n; i++) {
            string currTime = timePoints[i];
            int hour = stoi(currTime.substr(0, 2)),
                min = stoi(currTime.substr(3, 2));

            times[i] = hour * 60 + min;
        }

        sort(times.begin(), times.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }

        minDiff =
            min(minDiff, (times[0] - times[n - 1] + (24 * 60)) % (24 * 60));

        return minDiff;
    }
};