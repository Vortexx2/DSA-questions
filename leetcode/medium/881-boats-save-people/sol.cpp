/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Probelm 881 - Number of Boats to Save People
 * @date 04-05-2024
 *
 * Runtime - 60 ms O(n*log(n))
 * Memory - 45.27 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int numBoats = 0;

        int left = 0, right = people.size() - 1;
        while (right >= left) {
            if (people[right] == limit) {
                numBoats++;
                right--;
            }

            else if (people[left] + people[right] <= limit) {
                numBoats++;
                left++;
                right--;
            }

            else {
                numBoats++;
                right--;
            }
        }

        return numBoats;
    }
};