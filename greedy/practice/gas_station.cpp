#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/gas-station/
// Med. Implementing the clean concise solution is difficult.
// Messy solution is easy to reason about, but gets too messy impl.

class Solution {
   public:

    // Concise Solve. Best.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? start : -1;
    }

    // Messy-Solve.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, cur_station = 0;
        int cur_gas = 0;
        bool moved = false;
        while (start < n) {
            cout << start << endl;
            if (moved && cur_station % n == start) {
                return start;
            }
            cur_gas += gas[cur_station] - cost[cur_station];

            if (cur_gas < 0) {
                // Reset
                if (moved && cur_station <= start) {
                    return -1;
                }
                start = cur_station + 1;
                cur_gas = 0;
                cur_station = (cur_station + 1) % n;
                moved = false;
            } else {
                // Keep Moving
                moved = true;
                cur_station = (cur_station + 1) % n;
            }
        }
        return -1;
    }
};