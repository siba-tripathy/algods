#include <bits/stdc++.h>

using namespace std;

// LC : AC : V fEasy : Good :

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] < target)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};