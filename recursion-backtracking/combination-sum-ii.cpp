#include <bits/stdc++.h>
using namespace std;

// Hard. The duplicate avoidance logic is hard to reason about and tricky to implmement.
// Great Problem.
// LC: https://leetcode.com/problems/combination-sum-ii/


class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        getCombos(ans, candidates, arr, 0, target);
        return ans;
    }

    void getCombos(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur_set, int pos, int target) {
        if (target == 0) {
            ans.push_back(cur_set);
            return;
        }
        if (pos >= candidates.size() || target < 0) {
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i - 1]) continue;  // skip if same element has been chosen in this iteration
            cur_set.push_back(candidates[i]);
            getCombos(ans, candidates, cur_set, i + 1, target - candidates[i]);
            cur_set.pop_back();
        }
    }
};