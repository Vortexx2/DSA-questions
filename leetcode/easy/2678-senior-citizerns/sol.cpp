/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 2678 - Number of Senior Citizens
 * 
 * @date 2024-08-01
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int numOld = 0;
        for (auto &deet: details) {
            int age = stoi(deet.substr(11, 2));

            if (age >= 60) numOld++;
        }

        return numOld;
    }
};