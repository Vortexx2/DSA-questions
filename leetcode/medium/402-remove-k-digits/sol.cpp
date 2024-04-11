/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 402 - Remove K Digits
 * @approach Using a monotonic stack
 * @date 11-04-2024
 *
 * Runtime - 6 ms O(n)
 * Memory Usage - 10.65 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeKdigits(string num, int k) {
        // if number of digits to remove is >= than number of digits in the
        // number itself
        if (num.size() <= k) return "0";

        stack<char> st;

        for (auto &ch : num) {
            while (k > 0 && !st.empty() && ch < st.top()) {
                if (ch == 0) {
                }
                st.pop();
                k--;
            }

            st.push(ch);
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        res = res.substr(0, res.size() - k);
        res = removeLeadingZeros(res);

        return res.size() ? res : "0";
    }

    string removeLeadingZeros(string num) {
        int i = 0;
        while (num[i] == '0') i++;
        return num.erase(0, i);
    }
};