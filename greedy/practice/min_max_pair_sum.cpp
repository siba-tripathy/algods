#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Easy. But Proof is great. Refer notes or LC editorial.

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_max_sum = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            min_max_sum = max(min_max_sum, nums[i] + nums[nums.size() - 1 - i]);
        }
        return min_max_sum;
    }
};