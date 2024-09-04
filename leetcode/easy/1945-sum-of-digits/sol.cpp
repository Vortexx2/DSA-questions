/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1945 - Sum of Digits of String After Convert
 * 
 * Runtime - 0 ms 
 * Memory Usage - 10.05 MB O(1)
 * @date 2024-09-04
 */
#include <bits/stdc++.h>

using namespace std;

int sum_string(string s) {
    int res = 0;
    for (auto &ch : s) {
        res += int(ch) - 48;
    }
    return res;
}

int find_digit_sum(int num) {
    int res = 0;
    while (num) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

class Solution {
   public:
    int getLucky(string s, int k) {
        string t;

        int res = 0;

        // convert to integers
        for (auto &ch : s) {
            int num = ch - 'a' + 1;
            t += to_string(num);
        }
        res = sum_string(t);
        k--;

        while (k) {
            res = find_digit_sum(res);
            k--;
        }

        return res;
    }
};