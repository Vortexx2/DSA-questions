/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 179 - Largest Number
 * 
 * l = length of list
 * m = max number of characters
 * Runtime - 0 ms O(l * m log(l))
 * Memory Usage - 17.28 MB O(l * m)
 * @date 2024-09-18
 */
#include <bits/stdc++.h>

using namespace std;

// -------------------------- SADLY THE BELOW DID NOT WORK -----------------------------------

// bool customStringSort(string a, string b) {
//     int aLength = a.size(), bLength = b.size();
//     int minLength = min(aLength, bLength);

//     int i = 0;
//     while (i < minLength) {
//         if (a[i] < b[i])
//             return false;

//         else if (a[i] > b[i])
//             return true;

//         i++;
//     }

//     if (aLength == bLength) return false;

//     // if code reaches here that means that 1 is a substring of the other
//     // eg. 332 and 33
//     // now all we do is we check if the last element for the shorter one (33
//     // 3) is greater than or smaller than the next element in the longer one
//     // (332 -> 2)
//     else if (aLength < bLength) {
//         if (a[aLength - 1] > b[i]) return true;

//         // if 33, 334 return false
//         return false;
//     }

//     // this means that bLength < aLength
//     if (b[bLength - 1] > a[i]) return false;

//     return true;
// }

bool customStringSort(string& a, string& b) {
    string aFirst = a + b, bFirst = b + a;

    return aFirst > bFirst;
}

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> stringNums(n, "");

        // convert all numbers to strings in this new array
        for (int i = 0; i < n; i++) {
            stringNums[i] = to_string(nums[i]);
        }

        // sort them according to the custom rule we set
        sort(stringNums.begin(), stringNums.end(), customStringSort);

        if (stringNums[0] == "0") return "0";

        string res = "";
        for (auto& num : stringNums) {
            res += num;
        }

        return res;
    }
};