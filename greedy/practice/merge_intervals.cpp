#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/merge-intervals/description/
// Med. Good Impl. Great imp case handling.

class Solution {
   public:
    struct VectorComp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), VectorComp());
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= lastEnd) {
                lastEnd = max(lastEnd, intervals[i][1]);  // V IMP
            } else {
                ans.push_back(vector<int>{lastStart, lastEnd});
                lastStart = intervals[i][0];
                lastEnd = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{lastStart, lastEnd});
        return ans;
    }
};

int main() {
    return 0;
}