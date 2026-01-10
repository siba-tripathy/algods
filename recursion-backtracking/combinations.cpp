#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/combinations/
// Easy-Med. Good short warm up problem.

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> cur;
        getCombinations(combinations, cur, 1, 0, k, n);
        return combinations;
    }

    void getCombinations(vector<vector<int>>& ans, vector<int>& curset, int cur, int cur_included_count, int k, int n) {
        if (cur_included_count == k) {
            ans.push_back(curset);
            return;
        }
        if (cur > n) {
            return;
        }
        /// include(pick cur)
        curset.push_back(cur);
        getCombinations(ans, curset, cur + 1, cur_included_count + 1, k, n);

        // backtrack
        curset.pop_back();
        // exclude(not picking cur)
        getCombinations(ans, curset, cur + 1, cur_included_count, k, n);
    }
};