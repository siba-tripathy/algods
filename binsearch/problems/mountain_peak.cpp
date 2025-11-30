#include <bits/stdc++.h>

using namespace std;

// Medium. Great
// LC: https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            // to ignore mid on left edge, as strictly mountain
            if (mid == 0)
            {
                left = mid + 1;
                continue;
            }
            else if (mid == arr.size() - 1)
            { // to ignore mid on right edge, as strictly mountain
                right--;
                continue;
            }

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            { // striclty unequal consecutive as strictly mountain
                return mid;
            }
            else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};