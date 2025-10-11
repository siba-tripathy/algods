#include<bits/stdc++.h>
using namespace std;

// Great Medium Question :: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int s = -1, e = nums.size();
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= nums[i - 1])
            {
                s = i;
            }
            else
            {
                break;
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
            {
                e = i;
            }
            else
            {
                break;
            }
        }
        int min_in_right_of_s = INT_MAX, max_in_left_of_e = INT_MIN; // to make sure 0 to s is actually the sorted correct position array
        for (int i = s + 1; i < nums.size(); i++)
        {
            min_in_right_of_s = min(min_in_right_of_s, nums[i]);
        }
        for (int i = e - 1; i >= 0; i--)
        {
            max_in_left_of_e = max(max_in_left_of_e, nums[i]);
        }
        while (s >= 0 && nums[s] > min_in_right_of_s)
        {
            s--;
        }
        while (e <= nums.size() - 1 && nums[e] < max_in_left_of_e)
        {
            e++;
        }
        return max(0, e - s - 1);
    }
};