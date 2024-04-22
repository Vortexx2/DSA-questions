/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 752 - Open The Lock
 * @date 23-04-2024
 * @approach Using BFS shortest path
 *
 * Runtime - 389 ms
 * Memory Usage - 37.4 MB
 */
#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first;
    }
};

class Solution {
   public:
    char increase(char c) {
        if (c == '9') return '0';
        return c + 1;
    }

    char decrease(char c) {
        if (c == '0') return '9';

        return c - 1;
    }

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        set<string> deads, visited;
        for (auto& d : deadends) deads.insert(d);

        string curr = "0000";
        if (deads.find(curr) != deads.end()) return -1;

        // will store (dist, val)
        queue<pair<int, string>> pq;
        pq.push({0, curr});

        int currMoves = 0;
        string newStr;

        while (!pq.empty()) {
            tie(currMoves, curr) = pq.front();
            pq.pop();
            visited.insert(curr);

            for (int i = 0; i < curr.size(); i++) {
                for (int shouldInc = 0; shouldInc <= 1; shouldInc++) {
                    if (shouldInc)
                        newStr = curr.substr(0, i) + increase(curr.at(i)) +
                                 curr.substr(i + 1, curr.size() - i - 1);
                    else
                        newStr = curr.substr(0, i) + decrease(curr.at(i)) +
                                 curr.substr(i + 1, curr.size() - i - 1);

                    if (visited.find(newStr) != visited.end() ||
                        deads.find(newStr) != deads.end())
                        continue;

                    if (newStr == target) return currMoves + 1;

                    pq.push({currMoves + 1, newStr});
                    visited.insert(newStr);
                }
            }
        }

        return -1;
    }
};