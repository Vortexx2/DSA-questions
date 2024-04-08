/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1700 - Number of Students Unable to Eat Lunch
 * @date 08-04-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 11.38 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        unordered_map<int, int> check;
        for (auto &num : students)
        {
            check[num]++;
        }

        int ans = 0;

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (check[sandwiches[i]])
                check[sandwiches[i]]--;

            else
            {
                ans += sandwiches.size() - i;
                break;
            }
        }

        return ans;
    }
};