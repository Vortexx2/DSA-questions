/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 514 - Freedom Trail
 * @approach Using top down DP
 * @date 27-04-2024
 *
 * Runtime - 29 ms
 * Memory Usage - 22.15 MB
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    unordered_map<char, vector<int>> charDic;

    // will store: {index in ring, index in key} -> cached result if there is
    // any
    map<pair<int, int>, int> dp;

    string ring, key;

    int findRotateSteps(string ring, string key) {
        this->ring = ring, this->key = key;
        charDic = {};

        // store all unique values in a set for quick access
        unordered_set<char> keySet;
        for (auto &ch : key) keySet.insert(ch);

        // insert all positions for each character appearing in the key into
        // charDic
        for (int i = 0; i < ring.size(); i++) {
            char ringChar = ring[i];
            if (keySet.find(ringChar) != keySet.end())
                charDic[ringChar].push_back(i);
        }

        return rec(0, 0) + key.size();
    }

    int rec(int ringIndex, int keyIndex) {
        if (keyIndex == key.size()) return 0;

        if (dp[{ringIndex, keyIndex}]) return dp[{ringIndex, keyIndex}];

        if (ring[ringIndex] == key[keyIndex])
            return rec(ringIndex, keyIndex + 1);

        int minT = INT_MAX;
        for (auto &nextPos : charDic[key[keyIndex]]) {
            int numMoves;
            if (ringIndex < nextPos)
                numMoves = min(nextPos - ringIndex,
                               ringIndex + (int(ring.size()) - nextPos));

            else
                numMoves = min(ringIndex - nextPos,
                               (int(ring.size()) - ringIndex) + nextPos);

            minT = min(minT, numMoves + rec(nextPos, keyIndex + 1));
        }

        dp[{ringIndex, keyIndex}] = minT;

        return minT;
    }
};