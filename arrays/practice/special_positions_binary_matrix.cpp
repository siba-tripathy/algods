#include<bits/stdc++.h>

using namespace std;

// LC : ~AC : Easy : No Trick : https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        vector<int> rows_sums, cols_sums;
        int ans = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int row_sum = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                row_sum += mat[i][j];
            }
            rows_sums.push_back(row_sum);
        }

        for (int j = 0; j < mat[0].size(); j++)
        {
            int col_sum = 0;
            for (int i = 0; i < mat.size(); i++)
            {
                col_sum += mat[i][j];
            }
            cols_sums.push_back(col_sum);
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1 && rows_sums[i] == 1 && cols_sums[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};