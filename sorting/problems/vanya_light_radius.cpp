#include<bits/stdc++.h>

using namespace std;

// Easy. Good. Not AC due to some accuracy diff still.
// CF: https://codeforces.com/contest/492/problem/B

int main() {
    int n, l;
    cin>>n>>l;
    vector<float> lanterns(n);
    for (int i=0; i<n ; i++) {
        cin>>lanterns[i];
    }
    sort(lanterns.begin(), lanterns.end());
    double max_diff = (double)(lanterns[0] - 0);
    for (int i=1; i<n; i++) {
        max_diff = max(max_diff, (double)((lanterns[i] - lanterns[i - 1]) / 2.0f));
    }
    max_diff = max(max_diff, (double)(l - lanterns[n - 1]));
    cout<<fixed<<setprecision(10)<<max_diff;
    return 0;
}