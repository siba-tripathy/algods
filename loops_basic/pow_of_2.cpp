#include<bits/stdc++.h>

using namespace std;

// LC : AC : Easy : https://leetcode.com/problems/power-of-two/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                break;
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