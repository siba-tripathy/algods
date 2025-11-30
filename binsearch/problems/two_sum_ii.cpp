#include <bits/stdc++.h>

using namespace std;

// Easy
// LC: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int left = i + 1, right = numbers.size() - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (numbers[mid] == target - numbers[i])
                {
                    return vector<int>({i + 1, mid + 1});
                }
                else if (numbers[mid] < target - numbers[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return vector<int>({-1, -1});
    }
};