/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1717 - Maximum Score From Removing Substrings
 * @date 13-07-2024
 *
 * Runtime - 377 ms O(n)
 * Memory Usage - 382.38 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maximumGain(string s, int x, int y) {
        // in the stack we will only push a or
        stack<char> st;
        int maxScore = 0;

        for (auto &ch : s) {
            if (st.empty() || st.top() == ch || (ch != 'a' && ch != 'b') ||
                (st.top() != 'a' && st.top() != 'b'))
                st.push(ch);

            else if (ch == 'a') {
                // since st.top() != ch
                // therefore st.top() == 'b'

                // ab is more valuable
                if (x > y) st.push(ch);

                // ba is more valuable
                // and since we are greedy, we insta-pop
                else {
                    maxScore += y;
                    st.pop();
                }
            }

            else if (ch == 'b') {
                // since st.top() != ch
                // therefore st.top() == 'a'

                // ab is more valuable
                if (x > y) {
                    maxScore += x;
                    st.pop();
                }

                // ba is more valuable
                else
                    st.push(ch);
            }
        }

        queue<char> q;
        while (!st.empty()) {
            if (st.top() != 'a' && st.top() != 'b')
                q = queue<char>();

            else if (q.empty() || st.top() == q.front()) {
                q.push(st.top());
            }

            else {
                while (!st.empty() && !q.empty() && st.top() != q.front() &&
                       (st.top() == 'a' || st.top() == 'b')) {
                    if (st.top() == 'a') {
                        maxScore += x;
                    } else
                        maxScore += y;
                    st.pop();
                    q.pop();
                }

                continue;
            }

            st.pop();
        }

        return maxScore;
    }
};