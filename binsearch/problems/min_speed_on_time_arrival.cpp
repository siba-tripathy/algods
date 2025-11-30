#include <bits/stdc++.h>

using namespace std;

// Easy med. Calc imp.
// LC: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        long long int totalDist = 0;
        for (int x : dist)
        {
            totalDist += x;
        }
        int min_speed = floor(totalDist / hour), max_speed = 10000000, ans = -1;
        while (min_speed <= max_speed)
        {
            int mid = (min_speed + max_speed) / 2;
            if (timeTaken(mid, dist) <= hour)
            {
                ans = mid;
                max_speed = mid - 1; // MINI
            }
            else
            {
                min_speed = mid + 1;
            }
        }
        return ans;
    }

    double timeTaken(int speed, vector<int> &dist)
    {
        double time = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            if (i < dist.size() - 1)
            {
                time += ceil((double)dist[i] / speed); // because in between trains we need to wait for next whole hour
            }
            else
            {
                time += (double)dist[i] / speed;
            }
        }
        return (double)time;
    }
};