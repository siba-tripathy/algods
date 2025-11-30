#include <bits/stdc++.h>

using namespace std;

// Medium. Generic Pattern. Thinking which approach can be confusing. If greedy/straight up ans calculation does not seem straight forward, always
// see if ans is binary searchable.
// LC: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        int n = price.size();
        int min_taste = 0, max_taste = price[n - 1] - price[0];
        int ans = 0;
        while (min_taste <= max_taste)
        {
            int mid = (min_taste + max_taste) / 2;
            if (candiesSelectedWithMinDiff(price, mid) >= k)
            {
                ans = mid;
                min_taste = mid + 1; // MAXI
            }
            else
            {
                max_taste = mid - 1;
            }
        }
        return ans;
    }

    // greedy approach to sort and select next element with x min_diff, starting with 0th index
    // MIN step (minimize step of maxi-min)
    int candiesSelectedWithMinDiff(vector<int> &price, int min_diff)
    {
        int count = 1, last_element = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i] - last_element >= min_diff)
            {
                count++;
                last_element = price[i];
            }
        }
        return count;
    }
};