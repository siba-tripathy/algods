#include <bits/stdc++.h>

using namespace std;

// LC: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Easy

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int total = 0, maxWeight = 0;
        for (int x : weights)
        {
            total += x;
            maxWeight = max(maxWeight, x);
        }
        int min = maxWeight;
        int max = total;
        int ans = max;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            if (daysNeededToShipAllWithCapacity(weights, mid) <= days)
            {
                ans = mid;
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
        }
        return ans;
    }

    int daysNeededToShipAllWithCapacity(vector<int> &weights, int capacity)
    {
        int days = 0, curBag = 0;
        for (int x : weights)
        {
            if (curBag + x > capacity)
            {
                days++;
                curBag = 0;
            }
            curBag += x;
        }
        if (curBag >= 0)
        {
            days++;
        }
        return days;
    }
};