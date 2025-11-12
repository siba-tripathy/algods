#include<bits/stdc++.h>

using namespace std;

// Medium. Good. https://codeforces.com/gym/102961/problem/I

int main() {
    long long int n;
    cin>>n;
    vector<long long int> a(n);
    vector<long long int> pref_sum(n);

    for(long long int i=0; i<n; i++) {
        cin>>a[i];
    }

    sort(a.begin(), a.end());

    for (long long int i = 0; i < n; i++)
    {
        if (i == 0) {
            pref_sum[i] = a[i];
        } else {
            pref_sum[i] = pref_sum[i - 1] + a[i];
        }
    }
    long long int min_cost = LLONG_MAX;

    for (long long int i = 0; i < n; i++)
    {
        long long int left_cost = 0, right_cost = 0;
        if (i>0) {
            left_cost = i*a[i] - pref_sum[i-1];
        }
        if (i<n-1) {
            right_cost = pref_sum[n-1]-pref_sum[i]-(n-1-i)*a[i];
        }
        min_cost=min(min_cost, left_cost+right_cost);
    }
    cout<<min_cost;
    return 0;
}