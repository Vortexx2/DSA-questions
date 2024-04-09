/**
 * @file loop.cpp
 * @author Vortexx2
 * @brief Problem 2073 - Time Needed to Buy Tickets
 * @date 09-04-2024
 *
 * Runtime - 0 ms O(tickets * max_ticket)
 * Memory Usage - 9.42 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        while (tickets[k])
        {
            for (int i = 0; i < tickets.size(); i++)
            {
                if (tickets[i])
                {
                    time++;
                    tickets[i]--;
                }

                if ((i == k) && (!tickets[i]))
                    return time;
            }
        }

        return time;
    }
};