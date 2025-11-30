#include<bits/stdc++.h>

using namespace std;

// Easy-Med
// Lc: https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int col = matrix[0].size();
        int top = 0, bottom = matrix.size() - 1, targetRow = -1;
        while (top <= bottom)
        {
            int midrow = (top + bottom) / 2;
            if (matrix[midrow][0] <= target && matrix[midrow][col - 1] >= target)
            {
                targetRow = midrow;
                break;
            }
            else if (matrix[midrow][0] > target)
            {
                bottom = midrow - 1;
            }
            else
            {
                top = midrow + 1;
            }
        }
        if (targetRow == -1)
        {

            return false;
        }
        else
        {
            int left = 0, right = col - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (matrix[targetRow][mid] == target)
                {
                    return true;
                }
                else if (matrix[targetRow][mid] > target)
                {

                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return false;
        }
    }
};