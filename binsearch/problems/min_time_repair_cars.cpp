#include <bits/stdc++.h>

using namespace std;

// Medium. Good Logic. Second calc no BS. Only direct formula preferred. Try this direct calc in future always.
// LC: https://leetcode.com/problems/minimum-time-to-repair-cars/

class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long start = 1, end = (long long)cars * (long long)cars * (long long)(*max_element(ranks.begin(), ranks.end()));
        long long ans = -1;
        while (start <= end)
        {
            long long mid = (start + end) / 2;
            if (maxCarsRepaired(ranks, mid, cars) >= cars)
            {                  // MAX
                ans = mid;     // possible ans
                end = mid - 1; // MINI
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }

    long long maxCarsRepaired(vector<int> &ranks, long long time, int totalCars)
    {
        int start = 0, end = totalCars;
        long long ans = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            ans += sqrt(time / ranks[i]);
        }
        // cout<<ans<<endl;
        return ans;
    }
};