#include<bits/stdc++.h>
using namespace std;

// Hard: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// Impl is very good. Will teach a lot about c++ STL stuff.

class Solution {    


   public:
    struct FirstDesc {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        }
    };
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n=deadline.size();
        vector<pair<int, int>> jobs(n);
        int max_deadline=0;
        for (int i=0; i<deadline.size(); i++) {
            jobs[i]=pair<int, int>(profit[i], deadline[i]);
            max_deadline=max(max_deadline, deadline[i]);
        }
        
        set<int> available_slots;
        for (int i=1; i<=max_deadline; i++) {
            available_slots.insert(i);
        }

        sort(jobs.begin(), jobs.end(), FirstDesc());

        int total_profit = 0;
        int total_jobs=0;

        for (int i=0; i<n; i++) {
            if (available_slots.empty()) {
                break;
            }
            auto ub = available_slots.upper_bound(jobs[i].second);
            if (ub == available_slots.begin()) {
                continue;
            }
            ub--;
            available_slots.erase(*ub);
            total_profit+=jobs[i].first;
            total_jobs++;
        }
        return vector<int>{total_jobs, total_profit};
    }
};