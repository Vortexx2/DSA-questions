/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1701 - Average Waiting Time
 * @date 09-07-2024
 *
 * Runtime - 137 ms O(n)
 * Memory Usage - 76.58 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime =
            customers[0][0];  // set it to the first customer's arrival time
        long totalWaitingTime = 0;

        // p will be a 2 element vector, arrival time, preparing time
        for (auto& p : customers) {
            currTime = max(p[0], currTime);
            totalWaitingTime += (currTime - p[0]) + p[1];

            currTime += p[1];
        }

        return (double)totalWaitingTime / customers.size();
    }
};