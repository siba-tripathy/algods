#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int size = mat.size();
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans += mat[i][i] + mat[i][size - 1 - i];
        }
        if (size % 2 == 1)
        {
            ans -= mat[size / 2][size / 2];
        }
        return ans;
    }
};