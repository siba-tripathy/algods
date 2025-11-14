#include<bits/stdc++.h>

using namespace std;

// LC Med, Seems Hard, Great Intuition Quesiton if done in one-pass
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1, n = nums.size();
        while (i <= j)      // IMP, keeping i<=j, so that i==j is also checked and we move out of loop when j<i(inavlid conditon), all valids checked
        {
            int mid = (i + j) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // Even though the whole array isn’t sorted, one half is always sorted at every step we choose a mid.
            //  So if mid's left part is sorted(found by comparing with a[i]), and target lies in that left sorted part, consider that,
            //  clear search space for rest, and vice versa
            //  if mid's right part is sorted, check if that part has target and reduce search space accordingly
            //  fact is that, search space reduction is imp, and it can be done only when we deal with the sorted part(whole left or
            //  whole right part) of the mid
            if (nums[mid] >= nums[i])
            { // mid's left part is sorted
                if (nums[i] <= target && target < nums[mid])
                { // surity can only come from sorted part
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else
            { // mid's right part is sorted
                if (nums[mid] < target && target <= nums[j])
                { // surity can only come from sorted part
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }

        return -1;
    }
};