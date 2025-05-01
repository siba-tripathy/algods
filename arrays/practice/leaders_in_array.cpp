#include <bits/stdc++.h>

using namespace std;

// GFG : AC : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/0
// GOOD Q

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        int cur_max_from_right = arr[arr.size() - 1];
        vector<int> ans;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            cur_max_from_right = max(cur_max_from_right, arr[i]);
            if (arr[i] >= cur_max_from_right)
            {
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
