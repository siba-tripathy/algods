#include<bits/stdc++.h>

using namespace std;

// GFG : Easy : Good : https://www.geeksforgeeks.org/problems/count-sorted-rows2702/1

class Solution
{
public:
    int sortedCount(int N, int M, vector<vector<int>> Mat)
    {
        // code here

        if (M <= 1)
        {
            return N;
        }
        if (M == 2)
        {
            int ans = N;
            for (int i = 0; i < N; i++)
            {
                if (Mat[i][0] == Mat[i][1])
                {
                    ans--;
                }
            }
            return ans;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            bool sorted = true;
            for (int j = 1; j < M - 1; j++)
            {
                if (!((Mat[i][j - 1] < Mat[i][j] && Mat[i][j] < Mat[i][j + 1]) || // strictly increasing
                      (Mat[i][j - 1] > Mat[i][j] && Mat[i][j] > Mat[i][j + 1])))
                { // strictly decreasing
                    sorted = false;
                    break;
                }
            }
            if (sorted)
            {
                ans++;
            }
        }
        return ans;
    }
};