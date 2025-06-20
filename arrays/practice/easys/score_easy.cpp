#include<bits/stdc++.h>

using namespace std;

// V Easy: LC : Meh : https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/

class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        vector<long long int> ans(nums.size());
        long long int maximum = 0, scoreSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maximum = maximum > nums[i] ? maximum : nums[i];
            scoreSum += maximum + nums[i];
            ans[i] = scoreSum;
        }
        return ans;
    }
};