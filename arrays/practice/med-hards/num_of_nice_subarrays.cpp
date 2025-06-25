#include<bits/stdc++.h>

using namespace std;

// Med-Hard. Great Q. https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// Based on same pattern as https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> odds(nums.size(), 0);
        vector<int> freq(60000, 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] % 2 == 1 ? odds[i] = 1 : odds[i] = 0; // first calculate odd-ness
            if (i != 0)
            {
                odds[i] += odds[i - 1]; // then do prefix_sum
            }
            if (odds[i] == k)
            {
                ans++; // sub-array starting at beginning index(0 index)
            }
            if (odds[i] >= k)
            {
                ans += freq[odds[i] - k]; // sub-arrays starting later, after(next index) those places where pref_sum was == cur - goal
            }
            freq[odds[i]]++;
        }
        return ans;
    }
};