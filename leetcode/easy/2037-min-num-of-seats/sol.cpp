#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void countSort(vector<int>& vec) {
        int largest = 101;
        vector<int> counts(largest, 0);

        for (auto& num : vec) counts[num]++;

        int vecPointer = 0;
        for (int i = 0; i < counts.size(); i++) {
            while (counts[i]) {
                vec[vecPointer++] = i;
                counts[i]--;
            }
        }
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        countSort(seats);
        countSort(students);

        int res = 0;
        for (int i = 0; i < seats.size(); i++) {
            res += abs(seats[i] - students[i]);
        }

        return res;
    }
};