#include<bits/stdc++.h>

using namespace std;

// Great/ Easy medium problem.
// LC: https://leetcode.com/problems/most-beautiful-item-for-each-query

class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    { // IMP to do & to avoid copying and save time (STL good)
        return a[0] < b[0];
    }
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = items.size();
        int q = queries.size();
        sort(items.begin(), items.end(), compare);
        vector<int> prefix_best(n);
        vector<int> ans(q);
        prefix_best[0] = items[0][1];
        for (int i = 1; i < n; i++)
        {
            prefix_best[i] = max(prefix_best[i - 1], items[i][1]);
        }
        // will upperbound work with custom comparators?
        for (int i = 0; i < q; i++)
        {
            int ansq = 0, cost = queries[i];
            int start = 0, end = n - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if (items[mid][0] <= cost)
                {
                    ansq = prefix_best[mid];
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            ans[i] = ansq;
        }
        return ans;
    }
};