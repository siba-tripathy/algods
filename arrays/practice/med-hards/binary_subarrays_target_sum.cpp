#include<bits/stdc++.h>

using namespace std;

// Med - Hard, Great Q. https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        vector<int> freq(40000, 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                nums[i] = nums[i] + nums[i - 1]; // do prefix-sum if can be done (not for index == 0)
            }
            if (nums[i] == goal)
            {
                ans++; // sub-array starting at beginning index(0 index)
            }
            if (nums[i] >= goal)
            {
                ans += freq[nums[i] - goal]; // sub-arrays starting later, after(next index) those places where pref_sum was == cur - goal
            }
            freq[nums[i]]++;
        }
        return ans;
    }
};