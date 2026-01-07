#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
// Med. Great Problem.

class Solution {
   public:
    struct baloon {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
    };
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), baloon());
        int curEnd = points[0][1];
        int shots = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > curEnd) {
                shots++;
                curEnd = points[i][1];
            }
        }
        return shots;
    }
};