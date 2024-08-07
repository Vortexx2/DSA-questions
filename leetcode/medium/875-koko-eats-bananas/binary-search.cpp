/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 875 - Koko eating Bananas
 * @approach Using a Binary Search approach
 * 
 * Runtime - 291 ms O(n log m)
 * Memory Usage - 21.7MB O(1)
 * @date 2024-08-07
 */
#include <bits/stdc++.h>

using namespace std;

pair<int, int> findMinMaxInVec(vector<int>& arr) {
    int minEl = INT_MAX, maxEl = INT_MIN;
    for (auto& n : arr) {
        minEl = min(minEl, n);
        maxEl = max(maxEl, n);
    }

    return {minEl, maxEl};
}

class Solution {
   public:
    int numHoursToEatBananas(vector<int>& piles, int rate) {
        int totalHours = 0;
        for (auto& p : piles) totalHours += ceil((long double)p / rate);

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // in this question, Koko will always be able to finish the bananas
        // since h >= numPiles

        int numPiles = piles.size();
        int leastRate, mostRate;
        tie(leastRate, mostRate) = findMinMaxInVec(piles);

        int l = 1, r = mostRate + 1;
        int minRate = mostRate;

        while (l < r) {
            int mid = floor((l + r) / 2);

            if (numHoursToEatBananas(piles, mid) <= h) {
                minRate = min(minRate, mid);
                r = mid;
            }

            else
                l = mid + 1;
        }

        return minRate;
    }
};