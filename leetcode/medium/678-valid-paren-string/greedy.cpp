/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 678 - Valid Parenthesis String
 * @approach Greedy solution
 * @date 07-04-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.2 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string a)
    {
        int leftMin = 0, leftMax = 0;

        for (auto &ch : a)
        {
            if (ch == '(')
            {
                leftMin++;
                leftMax++;
            }

            else if (ch == ')')
            {
                // if leftMax = 0, can't have any more rights allowed
                if (!leftMax)
                    return false;

                // only if leftMin is not 0
                if (leftMin)
                    leftMin--;

                leftMax--;
            }

            else
            {
                if (leftMin)
                    leftMin--;

                leftMax++;
            }
        }

        return leftMin == 0;
    }
};