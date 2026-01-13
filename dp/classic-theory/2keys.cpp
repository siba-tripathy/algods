#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/2-keys-keyboard/
//AC

class Solution {
   public:
    int minSteps(int n) { // Normal DP : O(n^2)
        vector<int> steps(n+1, INT_MAX);
        steps[1] = 0;
        for (int i=2; i<=n; i++) {
            for (int j=i-1; j>=1; j--) {
                if (i%j==0) {
                    steps[i]=min(steps[i], steps[j]+ (i/j));
                }
            }
        }
        return steps[n];
    }

    // math insight used : prime factorization (Time : O(√n))
    int minSteps(int n) {
        int ans = 0;
        for (int d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
        }
        if (n > 1) ans += n;
        return ans;
    }
};