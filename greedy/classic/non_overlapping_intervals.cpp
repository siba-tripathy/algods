#include <bits/stdc++.h>
using namespace std;

// V Tricky. Med - Hard. (HINT - DO NOT SEE BEFORE TYRING: ###Var@@@@@@@*******ce##of##ac##ti##vity##se$$$$$le$$$$$ct$$$$io$$$$$n)
// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
   public:
    bool static comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int ans = 0;
        int cur_end = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {
            if (cur_end > intervals[i][0]) {  // Remove this overlapping interval
                ans++;
            } else {  // non overlapping, take into current registry of valid intervals to be preserved
                cur_end = intervals[i][1];
            }
        }
        return ans;
    }
};