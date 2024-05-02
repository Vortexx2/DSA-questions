/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2441 - Largest Positive Integer That Exists With Its Negative
 * @date 02-05-2024
 *
 * Runtime - 28 ms O(n)
 * Memory Usage - 25.7 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        set<int> visited;

        int largest = -1;
        for (auto& num : nums) {
            if (visited.find(-num) != visited.end())
                largest = max(largest, abs(num));

            visited.insert(num);
        }

        return largest;
    }
};