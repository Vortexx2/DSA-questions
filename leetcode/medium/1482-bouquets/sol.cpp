/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1482 - Minimum Number of Days to make m bouquets
 * @approach Using Binary Search
 * @date 19-06-2024
 *
 * Runtime - 117 ms O(n * log (n))
 * Memory Usage - 68.9 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

pair<int, int> findMinMaxInVec(vector<int>& arr) {
    int minimum = INT_MAX, maximum = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        minimum = min(minimum, arr[i]);
        maximum = max(maximum, arr[i]);
    }

    return {minimum, maximum};
}

class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (n < m * k) return -1;

        int minBloom, maxBloom;
        tie(minBloom, maxBloom) = findMinMaxInVec(bloomDay);

        if (minBloom == maxBloom) return minBloom;

        // this stores our final result
        int minDaysRequired = maxBloom;

        // the current day we are testing for if the picking of m bouquets is
        // possible or not
        int currTest;
        while (minBloom <= maxBloom) {
            // we use the bsearch cliche
            currTest = floor((minBloom + maxBloom) / 2);

            // the following block of code checks how many bouquets are possible
            // at the current stage
            int consecutiveCounter = 0, numBouquets = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= currTest)
                    consecutiveCounter++;

                else {
                    numBouquets += floor(consecutiveCounter / k);
                    consecutiveCounter = 0;
                }
            }
            // just to clear any bouquets that we could have created at the end
            // of the sequence
            numBouquets += floor(consecutiveCounter / k);

            // if we can create m or more bouquets
            // then this is an acceptable solution
            // we set the maxBloom to currTest - 1
            // so as to reduce the search space now
            if (numBouquets >= m) {
                minDaysRequired = min(minDaysRequired, currTest);

                maxBloom = currTest - 1;
            }

            // if creating m bouquets was not possible
            // increase the lower bound of the window to currTest + 1
            else
                minBloom = currTest + 1;
        }

        return minDaysRequired;
    }
};

int main() {
    vector<int> b = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;

    Solution sol = Solution();
    int s = sol.minDays(b, m, k);
    cout << "MIN DAYS: " << s << endl;
}
