/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 678 - Valid Parenthesis String
 * @approach Recursive approach that uses an O(n) check at the end of the recursive loop
 * @date 07-04-2024
 *
 * Runtime - TLE
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> possible_subs = {"(", ")", " "};

    bool checkValidString(string a)
    {
        string res = a;
        return isValidRecursive(res, 0);
    }

    bool isValidRecursive(string &s, int i)
    {
        if (i == s.size())
            return actualValidCheck(s);

        if (s[i] != '*')
            return isValidRecursive(s, i + 1);

        for (auto &sub : possible_subs)
        {
            s[i] = sub.at(0);

            bool temp = isValidRecursive(s, i + 1);
            if (temp)
                return true;
        }

        s[i] = '*';
        return false;
    }

    bool actualValidCheck(string &s)
    {
        int items = 0;

        for (auto &ch : s)
        {
            if (ch == '(')
                items++;

            else if (ch == ')')
            {
                if (items == 0)
                    return false;
                items--;
            }
        }

        return items == 0;
    }
};