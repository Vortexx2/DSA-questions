/**
 * @file prefix.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1310 - XOR Queries of a Subarray
 * @approach Using a precompute / prefix approach
 * 
 * Runtime - 42 ms O(n)
 * Memory Usage - 41.52 MB O(n)
 * @date 2024-09-13
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int numElements = arr.size();
        int numQueries = queries.size();
        vector<int> prefixArr(numElements + 1, 0);

        for (int i = 1; i <= numElements; i++) {
            prefixArr[i] = prefixArr[i - 1] ^ arr[i - 1];
        }

        vector<int> res(numQueries, 0);
        for (int i = 0; i < numQueries; i++) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = prefixArr[r + 1] ^ prefixArr[l];
        }

        return res;
    }
};