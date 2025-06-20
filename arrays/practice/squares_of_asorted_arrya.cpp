#include<bits/stdc++.h>

using namespace std;

// V Good : LC : Easy : https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        vector<int> ans(nums.size());
        int ans_index = right;
        while (left < right)
        {
            cout << ans_index << " " << left << " " << right << endl;
            if (abs(nums[left]) > abs(nums[right]))
            {
                ans[ans_index] = nums[left] * nums[left];
                left++;
            }
            else
            {
                ans[ans_index] = nums[right] * nums[right];
                right--;
            }
            ans_index--;
        }
        if (left == right)
        { // two-pointers ended at mid element, handle it
            ans[ans_index] = nums[left] * nums[left];
        }
        return ans;
    }
};