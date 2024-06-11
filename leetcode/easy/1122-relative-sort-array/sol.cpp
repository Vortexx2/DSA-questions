/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1122 - Relative Sort Array
 * @date 11-06-2024
 *
 * Runtime - 5 ms O(n * log n)
 * Memory Usage - 10.18 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> countDic;
        for (auto& num : arr1) countDic[num]++;

        vector<int> res(arr1.size(), 0);
        int resPointer = 0;

        for (auto& num : arr2) {
            int count = countDic[num];
            while (count--) res[resPointer++] = num;

            countDic.erase(num);
        }

        if (resPointer == arr1.size()) return res;
        for (auto& it : countDic) {
            int count = it.second;
            while (count--) res[resPointer++] = it.first;
        }

        return res;
    }
};