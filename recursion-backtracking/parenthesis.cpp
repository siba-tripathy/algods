#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/generate-parentheses/
// Easy-Med. Good short warm up problem.

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getParenthesis(ans, "", n, 0, 0);
        return ans;
    }

    void getParenthesis(vector<string>& ans, string s, int n, int open, int close) {
        if (open == n && close == n) {
            ans.push_back(s);
        }
        if (open < n) {
            getParenthesis(ans, s + "(", n, open + 1, close);
        }
        if (close < n && close < open) {
            getParenthesis(ans, s + ")", n, open, close + 1);
        }
    }
};