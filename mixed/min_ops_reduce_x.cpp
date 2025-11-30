
#include <bits/stdc++.h>

using namespace std;

// Great Question. Med question. Needs thikning about problem more.

// LC: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        int target = total - x;
        if (target == 0)
        {
            return nums.size();
        }
        int i = 0, j = 0, sum = nums[0], max_length = -1;
        if (sum == target)
        {
            max_length = 1;
        }
        // sliding window : find max length subarray with sum == target
        while (j < nums.size() - 1)
        {
            j++;
            sum += nums[j];

            // shrink left till sum is under limit <= target
            while (sum > target && i < j)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == target)
            {
                max_length = max(max_length, j - i + 1);
            }
        }
        return max_length == -1 ? -1 : nums.size() - max_length;
    }
};