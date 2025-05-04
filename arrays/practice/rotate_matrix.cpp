#include<bits/stdc++.h>

using namespace std;

// LC : Medium : Trick : https://leetcode.com/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // transpose (rotate across diagonal)
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // reverse(rotate across mid column)
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size() / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[0].size() - 1 - j];
                matrix[i][matrix[0].size() - 1 - j] = temp;
            }
        }
    }
};