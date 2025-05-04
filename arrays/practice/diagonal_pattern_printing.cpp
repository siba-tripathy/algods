#include<bits/stdc++.h>

using namespace std;

// GFG : AC : Medium : VGood : https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        // Your code here
        int boundary = mat.size();
        string movement = "up_right";
        vector<int> ans;
        int i = 0, j = 0;
        while (true)
        {
            ans.push_back(mat[i][j]);
            if (i == boundary - 1 && j == boundary - 1)
            {
                break;
            }
            if (movement == "up_right")
            {
                if (j == boundary - 1)
                {
                    i++;
                    movement = "down_left";
                }
                else if (i == 0)
                {
                    j++;
                    movement = "down_left";
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else if (movement == "down_left")
            {
                if (i == boundary - 1)
                {
                    j++;
                    movement = "up_right";
                }
                else if (j == 0)
                {
                    i++;
                    movement = "up_right";
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};