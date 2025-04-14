#include <bits/stdc++.h>

using namespace std;

// LC : AC : https://leetcode.com/problems/ugly-number/description/
// GOOD Q

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1)
        {
            return false;
        }
        vector<int> allowed_factors = {2, 3, 5};
        int cur_factor_index = 0;
        while (n > 1)
        {
            if (n % allowed_factors[cur_factor_index] == 0)
            {
                n = n / allowed_factors[cur_factor_index];
            }
            else
            {
                if (cur_factor_index == allowed_factors.size() - 1)
                {
                    break;
                }
                else
                {
                    cur_factor_index++;
                }
            }
        }
        if (n == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};