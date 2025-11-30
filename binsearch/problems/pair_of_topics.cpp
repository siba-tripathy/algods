#include<bits/stdc++.h>

using namespace std;

// Great Q.
// https://codeforces.com/contest/1324/problem/D

int main() {
    int n;
    cin>>n;
    vector<int> a(n), b(n), diff(n);
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        diff[i] = a[i]-b[i];
    }

    sort(diff.begin(), diff.end());

    long long int ans=0;
    for (int i=0; i<n-1; i++) {
        ans+=diff.end()-upper_bound(diff.begin()+i+1, diff.end(), (-1)*diff[i]);
    }
    cout<<ans;
    return 0;

}