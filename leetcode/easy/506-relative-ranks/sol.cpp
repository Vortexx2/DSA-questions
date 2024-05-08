/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 506 - Relative Ranks
 * @date 08-05-2024
 *
 * Runtime - 11 ms O(n * log n)
 * Memory Usage - 13.82 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Compare {
   public:
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
};

class Solution {
   public:
    vector<string> findRelativeRanks(vector<int> &score) {
        // stores {score, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        int currScore, index;
        int currPos = 1;
        vector<string> res(score.size(), "");
        while (!pq.empty()) {
            tie(currScore, index) = pq.top();
            pq.pop();

            if (currPos == 1)
                res[index] = "Gold Medal";

            else if (currPos == 2)
                res[index] = "Silver Medal";

            else if (currPos == 3)
                res[index] = "Bronze Medal";

            else
                res[index] = to_string(currPos);

            currPos++;
        }

        return res;
    }
};