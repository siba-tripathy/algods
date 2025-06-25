#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> algos(n, 0);
    vector<int> wake(n, 0);
    int base_gain=0;

    for(int i=0; i<n; i++) {
        cin>>algos[i];
    }
    for(int i=0; i<n; i++) {
        cin>>wake[i];
        if (wake[i] == 1) {
            base_gain+=algos[i];
        }
    }

    int l=0, r=k-1, cur_gain=0;
    for(int i=0; i<=r; i++) {
        if (wake[i]==0) {
            cur_gain+=algos[i];
        }
    }

    int max_gain=cur_gain;

    while(r<n-1) {
        if (wake[l]==0) {
            cur_gain-=algos[l];
        }
        l++;
        r++;
        if(wake[r]==0) {
            cur_gain+=algos[r];
        }
        max_gain=max(max_gain, cur_gain);
    }
    cout<<base_gain+max_gain;
}