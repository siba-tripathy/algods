#include <bits/stdc++.h>
using namespace std;

// Only recursion does not work. Needs DP. But Very simple top-down DP (similar to recursion) with minimal meomization.
// LC: https://leetcode.com/problems/word-break/
// Easy

class Solution {
   public:
    unordered_map<string, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "") {
            return true;
        }
        if (memo.count(s)) return memo[s];  // check MEMOIZATION

        for (string dict : wordDict) {
            if (dict == s.substr(0, dict.size())) {
                // if no length given, substr takes till end
                bool isPossible = wordBreak(s.substr(dict.size()), wordDict);
                memo[s.substr(dict.size())] = isPossible;  // store if a sub string is buildable - MEMOIZATION done
                if (isPossible) {
                    return true;
                }
            }
        }
        return false;
    }
};