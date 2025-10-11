#include<bits/stdc++.h>

using namespace std;

// LC: Good. Easy-Med. https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
public:
    vector<vector<int>> pref_sum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            pref_sum.push_back(vector<int>(matrix[0].size()));
            for (int j = 0; j < matrix[0].size(); j++)
            {
                pref_sum[i][j] = pref(i, j - 1) + pref(i - 1, j) - pref(i - 1, j - 1) + matrix[i][j];
            }
        }
    }

    int pref(int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        return pref_sum[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return pref(row2, col2) - pref(row1 - 1, col2) - pref(row2, col1 - 1) + pref(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */