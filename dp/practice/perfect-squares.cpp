#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/perfect-squares
//nice question
//AC

class Solution {
   public:
    int numSquares(int n) {
        vector<int> minAdderCount(n + 1, -1);
        minAdderCount[0] = 0;
        // return numSquaresTopDown(n, minAdderCount);      //SLOWER = 146ms
        return numSquaresBottomUp(n);  // 34ms
    }

    int numSquaresTopDown(int n, vector<int>& minAdderCount) {
        if (minAdderCount[n] != -1) {
            return minAdderCount[n];
        } else {
            minAdderCount[n] = n;
            for (int i = 1; i <= 100 && i * i <= n; i++) {
                minAdderCount[n] = min(minAdderCount[n], 1 + numSquaresTopDown(n - i * i, minAdderCount));
            }
        }
        return minAdderCount[n];
    }

    int numSquaresBottomUp(int n) {
        vector<int> minAdderCount(n + 1, n);
        minAdderCount[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int target = i * i; target <= n; target++) {
                minAdderCount[target] = min(minAdderCount[target], minAdderCount[target - i * i] + 1);
            }
        }
        return minAdderCount[n];
    }
};