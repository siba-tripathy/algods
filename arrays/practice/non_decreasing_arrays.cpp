#include <bits/stdc++.h>
using namespace std;

// HE : Easy (V Good) : AC : https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/make-it-non-decreasing-7d3391fd/

int main()
{
    int t;
    cin >> t; // Reading input from STDIN
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> a(n);
        vector<long long int> b(n);
        long long int max_till_now = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
            {
                b[i] = a[i];
                max_till_now = a[i];
                continue;
            }
            if (max_till_now % a[i] == 0)
            {
                b[i] = max_till_now;
            }
            else
            {
                b[i] = a[i] * ((max_till_now / a[i]) + 1);
                max_till_now = b[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}