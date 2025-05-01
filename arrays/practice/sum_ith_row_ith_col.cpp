#include<bits/stdc++.h>

using namespace std;

// GFG : AC : Easy : Good : https://www.geeksforgeeks.org/problems/sums-of-i-th-row-and-i-th-column3054/0

int sumOfRowCol(int N, int M, vector<vector<int>> A)
{
    // code here
    int square_boundary = min(N, M);
    for (int i = 0; i < square_boundary; i++)
    {
        int col_sum = 0, row_sum = 0;
        for (int j = 0; j < M; j++)
        {
            row_sum += A[i][j];
        }

        for (int j = 0; j < N; j++)
        {
            col_sum += A[j][i];
        }
        if (row_sum != col_sum)
        {
            return 0;
        }
    }
    return 1;
};
