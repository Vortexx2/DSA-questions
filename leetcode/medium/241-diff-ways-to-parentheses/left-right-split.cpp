/**
 * @file left-right-split.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 241 - Different Ways to Add Parentheses
 * @approach Using a left right split method
 * 
 * Runtime - 8 ms
 * Memory Usage - 13.7 MB
 * @date 2024-09-19
 */
#include <bits/stdc++.h>

using namespace std;

int eval_expr(int a, string oper, int b) {
    if (oper == "+") return a + b;
    if (oper == "*") return a * b;
    return a - b;
}

class Solution {
   public:
    vector<int> diffWaysToCompute(string expr) {
        vector<int> res;
        int n = expr.size();

        // Base case: single number
        if (expr.find_first_of("+-*") == string::npos) return {stoi(expr)};

        // Split at each operator
        for (int i = 0; i < n; i++) {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                // Recursive call on left and right subexpressions
                vector<int> left = diffWaysToCompute(expr.substr(0, i));
                vector<int> right = diffWaysToCompute(expr.substr(i + 1));

                // Combine left and right results using the current operator
                for (int l : left) {
                    for (int r : right) {
                        cout << l << " " << string(1, expr[i]) << " " << r
                             << endl;
                        res.push_back(eval_expr(l, string(1, expr[i]), r));
                    }
                }
            }
        }

        return res;
    }
};
