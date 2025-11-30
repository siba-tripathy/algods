#include <bits/stdc++.h>

using namespace std;

// Medium. Generic Pattern.
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int min = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            if (countBouquets(bloomDay, mid, k) >= m)
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

    int countBouquets(vector<int> &bloomDay, int days, int k)
    {
        int curFlowers = 0, totalBouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] > days)
            {
                curFlowers = 0;
            }
            else
            {
                curFlowers++;
                if (curFlowers == k)
                {
                    totalBouquets++;
                    curFlowers = 0;
                }
            }
        }
        // cout<<"For mid days= "<<days<<", "<<totalBouquets<<" bouquets could be made."<<endl;
        return totalBouquets;
    }
};