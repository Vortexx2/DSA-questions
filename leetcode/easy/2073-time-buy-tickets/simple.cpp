/**
 * @file simple.cpp
 * @author Vortexx2
 * @brief Problem 2073 - Time Needed to Buy Tickets
 * @approach Using logic for 1 pass loop
 * @date 09-04-2024
 *
 * Runtime - 0ms O(1)
 * Memory Usage - 9.28 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int val = tickets[k];
        int time = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
            {
                if (tickets[i] < val)
                    time += tickets[i];
                else
                    time += val;
            }

            else
            {
                if (tickets[i] < val)
                    time += tickets[i];
                else
                    time += val - 1;
            }
        }

        return time;
    }
};