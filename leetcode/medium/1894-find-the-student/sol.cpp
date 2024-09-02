/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1894 - Find the Student that will replace the chalk
 * 
 * Runtime - 83 ms O(n)
 * Memory Usage - 77.08 MB O(1)
 * @date 2024-09-02
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long totalChalksNeeded = 0;
        for (auto& c : chalk) {
            totalChalksNeeded += c;
        }

        k = k % totalChalksNeeded;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }

        return chalk.size() - 1;
    }
};