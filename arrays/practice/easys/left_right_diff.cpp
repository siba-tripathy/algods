#include<bits/stdc++.h>

using namespace std;

// V Easy. Meh. https://leetcode.com/problems/left-and-right-sum-differences/

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        int leftSum = 0;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = abs(total - nums[i] - leftSum - leftSum);
            leftSum += nums[i];
        }
        return ans;
    }
};