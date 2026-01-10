#include <bits/stdc++.h>
using namespace std;

// Great Recursion backtracking problem.
// LC: https://leetcode.com/problems/combination-sum/
// hint : easy on the time limit, you can do lazy unique combination checks.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> arr;
        getCombos(ans, arr, candidates, target);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void getCombos(set<vector<int>>& ans, vector<int>& arr, vector<int>& candidates,  int target) {
        if (target==0) {
            vector<int> target_combo(arr.begin(), arr.end());
            sort(target_combo.begin(), target_combo.end());
            ans.insert(target_combo);
            return;
        }
        if (target<0) {
            return;
        }
        for (int i=0; i<candidates.size(); i++) {
            arr.push_back(candidates[i]);
            getCombos(ans, arr, candidates, target-candidates[i]);
            arr.pop_back();
        }
    }
};