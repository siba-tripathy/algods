#include<bits/stdc++.h>

using namespace std;

// Great Q. Med-Hard. https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        int ans = arr[arr.size() - 1] - arr[0]; // case considering all were done same operation: increased (decreased also would have same impact, overall diff wont change)
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int mini = min(arr[0] + k, arr[i + 1] - k);
            int maxi = max(arr[i] + k, arr[arr.size() - 1] - k);
            if (mini >= 0)
            { // no operation should result in any tower <0. If none apply, the above max-min based condition applies
                ans = min(ans, maxi - mini);
            }
        }
        return ans;
    }
};