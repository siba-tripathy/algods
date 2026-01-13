#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/climbing-stairs
// Easy. SIMple memo/////dp

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> waysCount(n + 1, -1);
        return getCounts(n, waysCount);
    }

    int getCounts(int n, vector<int>& waysCount) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (waysCount[n] != -1) {
            return waysCount[n];
        }
        waysCount[n] = getCounts(n - 1, waysCount) + getCounts(n - 2, waysCount);
        return waysCount[n];
    }
};