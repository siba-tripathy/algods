#include <bits/stdc++.h>

using namespace std;

// LC: https://leetcode.com/problems/koko-eating-bananas/
// Easy

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int min = 1; // better yet: sum of all piles size / h.
        int max = *(max_element(piles.begin(), piles.end())); // as can eat from one pile only at a time
        int ans = max;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            if (canEat(piles, mid, h))
            {
                ans = mid;
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
        }
        return ans;
    }

    bool canEat(vector<int> &piles, int speed, int h)
    {
        long long int timeTaken = 0;
        for (int x : piles)
        {
            timeTaken += x % speed == 0 ? (x / speed) : (x / speed) + 1;
        }
        return timeTaken <= h;
    }
};