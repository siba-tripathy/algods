#include<bits/stdc++.h>

using namespace std;

// Good. Medium. Slight Trick. LC : https://leetcode.com/problems/next-permutation/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return;
        }
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        { // find the first element from right which has a greater element to its right
            i--;
        }
        if (i >= 0)
        {                  // if i==-1, whole array descending, go for direct reversal
            int j = i + 1; // next largest digit to i, always will be there as we had found a descending pair to get i
            while (j <= n - 1 && nums[i] < nums[j])
            { // find next larger (not equals as lexically it would be same)
                j++;
            }
            j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }
    void reverse(vector<int> &nums, int i)
    {
        int j = nums.size() - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};