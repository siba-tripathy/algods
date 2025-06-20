#include<bits/stdc++.h>

using namespace std;

// Easy. Good Warmup. https://leetcode.com/problems/maximum-population-year/

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> living(2100, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            living[logs[i][0]]++;
            living[logs[i][1]]--;
        }

        int max = 0, max_year = 0;
        for (int i = 1950; i <= 2050; i++)
        {
            living[i] += living[i - 1];
            if (living[i] > max)
            {
                max = living[i];
                max_year = i;
            }
        }
        return max_year;
    }
};