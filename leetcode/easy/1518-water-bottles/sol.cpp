/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1518 - Water Bottles
 * @date 07-07-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunkBottles = 0;  // result that we return
        int currEmpty = 0;

        while (numBottles) {
            drunkBottles += numBottles;

            currEmpty += numBottles;
            numBottles = floor(currEmpty / numExchange);
            currEmpty = currEmpty % numExchange;
        }

        return drunkBottles;
    }
};