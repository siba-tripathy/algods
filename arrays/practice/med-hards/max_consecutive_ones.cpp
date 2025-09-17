#include <bits/stdc++.h>

using namespace std;

// Great, Medium, Common Pattern LC: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int cur_zeros = 0;
        int max_len = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
            {
                cur_zeros++;
            }
            while (cur_zeros > k)
            {
                if (nums[l] == 0)
                {
                    cur_zeros--;
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};