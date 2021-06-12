#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://www.spoj.com/status/NOTATRI
int main() {
    while(true) {
        int n;
        cin>>n;
        if(n==0) {
            break;
        }

        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                ans += arr.end() - upper_bound(arr.begin()+j+1, arr.end(), arr[i]+arr[j]);
            }
        }
        cout<<ans<<endl;
        
    }
}