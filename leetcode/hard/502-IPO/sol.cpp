/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problems 502 - IPO
 * @date 16-06-2024
 *
 * Runtime - 213 ms O(n log(n))
 * Memory Usage - 83.1 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

void coordAscendingSort(vector<int>& a, vector<int>& b) {
    // we will sort vector b in an order which is ascending for a
    vector<int> indices(a.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&a](int i, int j) { return a[i] < a[j]; });

    // Create sorted versions of 'a' and 'b' using the sorted indices
    vector<int> sorted_a(a.size());
    vector<int> sorted_b(b.size());

    for (int i = 0; i < indices.size(); ++i) {
        sorted_a[i] = a[indices[i]];
        sorted_b[i] = b[indices[i]];
    }

    // Replace the original vectors with the sorted versions
    a = sorted_a;
    b = sorted_b;
}

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        // first we will sort profits and capital based on
        // an ascending order of capital
        // second, we will create a priority queue for profits
        // third, we will only insert those profits into this
        // queue which has capitals <= current wealth

        // first, the sorting
        coordAscendingSort(capital, profits);

        if (capital[0] > w) return 0;

        // this stores the index of the profits in a priority queue
        priority_queue<int, vector<int>, function<bool(int, int)>> profitQ(
            [&profits](int i, int j) { return profits[i] < profits[j]; });

        int n = profits.size();
        int currentWealth = w,  // we initially start with w wealth
            right = 0;  // this stores all the projects we can afford based on
                        // our current capital

        while (k) {
            while (right < n && capital[right] <= currentWealth) {
                profitQ.push(right);
                right++;
            }

            if (profitQ.empty()) return currentWealth;

            int topChoiceIndex = profitQ.top();
            profitQ.pop();

            currentWealth += profits[topChoiceIndex];
            k--;
        }

        return currentWealth;
    }
};
