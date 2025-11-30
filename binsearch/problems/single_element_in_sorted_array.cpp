#include <bits/stdc++.h>

using namespace std;

// Medium. Tricky ans premise. Tricky edge case handling.
// LC : https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        if (left == right)
        {
            return nums[0];
        }
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // handle mid edges
            if (mid == 0)
            {
                if (nums[mid] < nums[mid + 1])
                {
                    return nums[mid];
                }
                else
                {
                    left++;
                }
            }

            if (mid == nums.size() - 1)
            {
                if (nums[mid] > nums[mid - 1])
                {
                    return nums[mid];
                }
                else
                {
                    right--;
                }
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            {
                return nums[mid];
            }
            else
            {
                if (mid % 2 == 0)
                {
                    if (nums[mid] == nums[mid + 1])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    if (nums[mid] == nums[mid - 1])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }
        return left;
    }
};