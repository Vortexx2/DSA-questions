/**
 * @file count-sort.cpp
 * @author Vortexx2
 * @brief Problem 1122 - Relative Sort Array
 * @approach Using count sort
 * @date 11-06-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 9.48 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());

        vector<int> counts(maxElement + 1);
        for (auto& num : arr1) counts[num]++;

        vector<int> res(arr1.size(), 0);
        int resPointer = 0;
        for (auto& num : arr2) {
            while (counts[num]) {
                res[resPointer++] = num;
                counts[num]--;
            }
        }

        if (resPointer == arr1.size()) return res;

        for (int i = 0; i < counts.size(); i++) {
            if (counts[i]) {
                while (counts[i]) {
                    res[resPointer++] = i;
                    counts[i]--;
                }
            }
        }

        return res;
    }
};