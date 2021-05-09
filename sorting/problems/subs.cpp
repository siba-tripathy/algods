#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        int min_diff = arr[k-1] - arr[0];
        for(int i=k; i<n; i++) {
            min_diff = min(min_diff, arr[i] - arr[i-k+1]);
        }
        cout<<min_diff<<endl;
    }
}