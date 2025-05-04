#include<bits/stdc++.h>

using namespace std;

// LC : Easy : VGood : https://leetcode.com/problems/toeplitz-matrix/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 1 || cols == 1)
        {
            return true;
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};