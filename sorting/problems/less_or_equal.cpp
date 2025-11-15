#include<bits/stdc++.h>

using namespace std;

// Easy. Trick edge case. cf: https://codeforces.com/contest/492/problem/B

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i =0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    if (k==n) {
        cout<<arr[n-1];
        return 0;
    }
    if (k==0) {
        if (arr[0]==1) {
            cout<<-1;
            return 0;
        } else {
            cout<<1;
            return 0;
        }
    }
    
    if (arr[k-1]<arr[k]) {
        cout<<arr[k-1];
        return 0;
    }
    cout<<-1;
    return 0;
    
}