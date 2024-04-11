/**
 * @file deque.cpp
 * @author Vortexx2
 * @brief Problem 950 - Reveal Cards in Increasing Order
 * @approach Using a deque
 * @date 11-04-2024
 *
 * Runtime - 3 ms O(n * log(n))
 * Memory Usage - 10.91 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> d;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) d.push_back(i);

        int currIndex = 0;
        bool include = true;
        while (!d.empty()) {
            int front = d.front();

            if (include) ans[front] = deck[currIndex++];

            // pop front in all cases
            d.pop_front();

            // if it is odd case push it back
            if (!include) d.push_back(front);

            include = !include;
        }

        return ans;
    }
};