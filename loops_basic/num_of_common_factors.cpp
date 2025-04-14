#include<bits/stdc++.h>

using namespace std;

// LC: AC : https://leetcode.com/problems/number-of-common-factors/description/
// Easy

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int small, big, ans = 0;
        if (a < b)
        {
            small = a;
            big = b;
        }
        else
        {
            small = b;
            big = a;
        }
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};