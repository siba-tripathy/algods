#include <bits/stdc++.h>

using namespace std;

// Good, Easy LC: https://leetcode.com/problems/maximum-difference-between-increasing-elements/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int prefix_min = nums[0];
        int max_diff = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_min = min(prefix_min, nums[i - 1]);
            max_diff = max(max_diff, nums[i] - prefix_min);
        }
        return max_diff <= 0 ? -1 : max_diff;
    }
};