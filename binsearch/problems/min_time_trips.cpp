#include <bits/stdc++.h>

using namespace std;

// Medium. Good Logic. Bad at int limit strictness.
// LC : https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long start = 1;
        long long end = (long long)totalTrips * 1LL * (long long)(*min_element(time.begin(), time.end()));
        long long ans;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            long long maxPossibleTrips = maxTripsCovered(time, mid); // MAX
            if (maxPossibleTrips >= totalTrips)
            {
                ans = mid;     // possible ans
                end = mid - 1; // keep looking for better, shorter time       // MINI
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }

    long long maxTripsCovered(vector<int> &tripTimes, long long time)
    {
        long long ans = 0;
        for (int i = 0; i < tripTimes.size(); i++)
        {
            ans += time / tripTimes[i];
        }
        return ans;
    }
};