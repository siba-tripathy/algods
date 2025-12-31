#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
// https://www.codechef.com/problems/HMAPPY

int main() {
    long long int n, m;
    cin>>n>>m;

    vector<long long int> arr(n, 0);
    vector<long long int> brr(n, 0);

    long long int max_candies_low = 0, max_candies_high = 1e18;// can be better, should be max of (a[i] * b[i])

    for(long long int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    for(long long int i = 0; i<n; i++) {
        cin>>brr[i];
    }

    long long int ans = 0;

    while(max_candies_low <= max_candies_high) {
        long long int mid = (max_candies_high + max_candies_low)/2;
        long long int ballons_needed = 0;
        for(int i = 0; i<n; i++) {
            ballons_needed += max((long long int)ceil(arr[i]*1.0 - (mid/brr[i]*1.0)), 0ll);
            // if (brr[i] <=0) 
            //     continue;
            // ballons_needed += max((arr[i] - (mid/brr[i])), 0ll);
            //0ll = (long long int)0
        }
        if (ballons_needed <= m) {
            ans = mid;
            max_candies_high = mid - 1;
        } else {
            max_candies_low = mid + 1;
        }
    }

    cout<<ans<<endl;
    
}