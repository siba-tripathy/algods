#include<bits/stdc++.h>

using namespace std;

// Good Easy https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ansSet;
        vector<int> emptyBase;
        generateSubset(nums, 0, emptyBase, ansSet);
        return ansSet;
    }

    void generateSubset(vector<int> &nums, int choiceIndex, vector<int> &currentSubset, vector<vector<int>> &ans)
    {
        // base case
        if (choiceIndex >= nums.size())
        {
            ans.push_back(currentSubset);
            return;
        }

        vector<int> includedSubset(currentSubset);
        includedSubset.push_back(nums[choiceIndex]);
        generateSubset(nums, choiceIndex + 1, includedSubset, ans);

        vector<int> excludedSubset(currentSubset);
        generateSubset(nums, choiceIndex + 1, excludedSubset, ans);
    }
};