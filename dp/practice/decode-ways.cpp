#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/decode-ways/editorial/
// Great 1-DP problem. Not like coin change.
// Below is a bottom-up approach  which was easy to visualize after understanding how letters could be decoded in two ways.
// This pattern is called Prefix DP with 1-step/2-step Transitions.

class Solution {
   public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.length();
        vector<int> counts(n, 0);
        counts[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') {
                counts[i] += counts[i - 1];
            }
            int pair_with_prev_value = stoi(s.substr(i - 1, 2));
            if (pair_with_prev_value >= 10 && pair_with_prev_value <= 26) {
                if (i <= 1) {
                    counts[i] += 1;
                } else {
                    counts[i] += counts[i - 2];
                }
            }
        }
        return counts[n - 1];
    }
};