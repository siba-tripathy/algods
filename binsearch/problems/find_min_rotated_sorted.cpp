#include <bits/stdc++.h>

using namespace std;

// LC Med, Seems Hard, Great Intuition Quesiton if pattern learnt
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            if (nums[left] <= nums[right])
                return nums[left]; // array already sorted

            int mid = (left + right) / 2;

            // mid element smaller than both sides ⇒ it's pivot
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];

            // right side is unsorted ⇒ pivot is there
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            // left side is unsorted ⇒ pivot is there
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};