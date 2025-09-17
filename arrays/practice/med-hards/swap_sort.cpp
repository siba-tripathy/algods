#include<bits/stdc++.h>
using namespace std;

// Great: CF: https://codeforces.com/contest/1638/problem/B

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        int last_even = 0, last_odd=0;
        bool good = true;
        for(int i=0; i<n; i++) {
            if (arr[i]%2 == 0) {
                if (last_even>arr[i]) {
                    good = false;
                    break;
                } else {
                    last_even = arr[i];
                }
            } else {
                if (last_odd > arr[i]) {
                    good = false;
                    break;
                } else {
                    last_odd = arr[i];
                }
            }
        }
        if (good) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
}