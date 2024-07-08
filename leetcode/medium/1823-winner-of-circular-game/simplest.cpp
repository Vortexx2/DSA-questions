/**
 * @file simplest.cpp
 * @author Vortexx2
 * @brief Problem 1823 - Find the Winner of the Circular Game
 * @date 08-07-2024
 *
 * Runtime - 0 ms O(n ^ 2)
 * Memory Usage - 7.43 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findTheWinner(int n, int k) {
        int currAlive = n;
        vector<int> aliveMask = vector<int>(n);
        for (int i = 1; i <= n; i++) aliveMask[i - 1] = i;

        int curr = 0;
        while (currAlive != 1) {
            curr = (curr + k - 1) % n;

            aliveMask.erase(aliveMask.begin() + curr);
            n--;
            currAlive--;
        }

        return aliveMask[0];
    }
};