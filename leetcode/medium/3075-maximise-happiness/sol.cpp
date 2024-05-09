/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 3075 - Maximise Happiness of Selected Children
 * @date 09-05-2024
 *
 * Runtime - 163 ms O(n * logn)
 * Memory Usage - 107 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long res = 0;
        int currDecreaseHappiness = 0;
        for (int i = 0; i < k; i++) {
            res += (max(0, happiness[i] - currDecreaseHappiness));
            currDecreaseHappiness++;
        }

        return res;
    }
};