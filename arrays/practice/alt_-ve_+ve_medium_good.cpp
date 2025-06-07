#include<bits/stdc++.h>

using namespace std;

// GFG : Very Good : Easy-Medium : https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        // code here
        int nextPositive = 0;
        int nextNegative = 0;

        while (nextPositive < arr.size() && arr[nextPositive] < 0)
        {
            nextPositive++;
        }

        while (nextNegative < arr.size() && arr[nextNegative] >= 0)
        {
            nextNegative++;
        }
        vector<int> ans(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                // positive
                if (nextPositive < arr.size())
                {
                    ans[i] = arr[nextPositive];
                    nextPositive++;
                    while (nextPositive < arr.size() && arr[nextPositive] < 0)
                    {
                        nextPositive++;
                    }
                }
                else
                {
                    ans[i] = arr[nextNegative];
                    nextNegative++;
                    while (nextNegative < arr.size() && arr[nextNegative] >= 0)
                    {
                        nextNegative++;
                    }
                }
            }
            else
            {
                // negative
                if (nextNegative < arr.size())
                {
                    ans[i] = arr[nextNegative];
                    nextNegative++;
                    while (nextNegative < arr.size() && arr[nextNegative] >= 0)
                    {
                        nextNegative++;
                    }
                }
                else
                {
                    ans[i] = arr[nextPositive];
                    nextPositive++;
                    while (nextPositive < arr.size() && arr[nextPositive] < 0)
                    {
                        nextPositive++;
                    }
                }
            }
        }
        arr = ans;
    }
};