#include<bits/stdc++.h>

using namespace std;

// LC: Medium : V Good : https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        string movement = "right";
        vector<int> ans;
        int left_border = 0, right_border = matrix[0].size() - 1, down_border = matrix.size() - 1, up_border = 0;
        int i = 0, j = 0;
        while (left_border <= right_border && up_border <= down_border)
        {
            ans.push_back(matrix[i][j]);
            // cout<<matrix[i][j]<<" "<<"(up="<<up_border<<" down="<<down_border<<")\n";
            if (movement == "right")
            {
                if (j == right_border)
                {
                    movement = "down";
                    up_border++;
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else if (movement == "down")
            {
                if (i == down_border)
                {
                    movement = "left";
                    right_border--;
                    j--;
                }
                else
                {
                    i++;
                }
            }
            else if (movement == "left")
            {
                if (j == left_border)
                {
                    movement = "up";
                    down_border--;
                    i--;
                }
                else
                {
                    j--;
                }
            }
            else if (movement == "up")
            {
                if (i == up_border)
                {
                    movement = "right";
                    left_border++;
                    j++;
                }
                else
                {
                    i--;
                }
            }
        }
        return ans;
    }
};