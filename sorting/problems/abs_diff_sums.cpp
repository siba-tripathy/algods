#include <iostream>
#include <vector>

using namespace std;

// LC :https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Great. Easy-Med. AC

class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        vector<int> pref_sum;
        vector<int> ans;
        pref_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            pref_sum.push_back(nums[i] + pref_sum[i - 1]);
        }

        int total = pref_sum[nums.size() - 1];

        for (int i = 0; i < nums.size(); i++)
        {
            int left_sum = 0, right_sum = 0;
            if (i > 0)
            {
                left_sum = i * nums[i] - pref_sum[i - 1];
            }
            if (i < nums.size() - 1)
            {
                int suffix_sum = total - pref_sum[i];
                right_sum = suffix_sum - (nums.size() - 1 - i) * nums[i];
            }
            ans.push_back(left_sum + right_sum);
        }
        return ans;
    }
};