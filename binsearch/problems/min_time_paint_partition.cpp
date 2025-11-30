#include <bits/stdc++.h>

using namespace std;

// Good. Med question.
// GFG: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution
{
public:
    int minTime(vector<int> &arr, int k)
    {
        int min_time_possible = arr[0]; // one worker per board
        int max_time_possible = arr[0]; // one worker all boards
        for (int i = 1; i < arr.size(); i++)
        {
            min_time_possible = max(min_time_possible, arr[i]);
            max_time_possible += arr[i];
        }
        int ans = max_time_possible;
        while (min_time_possible <= max_time_possible)
        {
            int mid = (min_time_possible + max_time_possible) / 2;
            if (paintersNeededForCompletionTime(arr, mid) <= k)
            {
                ans = mid;
                max_time_possible = mid - 1;
            }
            else
            {
                min_time_possible = mid + 1;
            }
        }
        return ans;
    }

    int paintersNeededForCompletionTime(vector<int> &arr, int completionTime)
    {
        int count = 1, cur_painter_time_taken = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] + cur_painter_time_taken > completionTime)
            {
                count++;
                cur_painter_time_taken = arr[i];
            }
            else
            {
                cur_painter_time_taken += arr[i];
            }
        }
        return count;
    }
};