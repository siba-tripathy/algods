#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

// CF: https://codeforces.com/contest/1337/problem/D
// Alternate Merge Flow Solution Would Work as well.

long long int calculateValue(long long int a, long long int b, long long int c) {
    // cout<<endl<<"A="<<a<<endl;
    // cout<<endl<<"B="<<b<<endl;
    // cout<<endl<<"C="<<c<<endl;
    return pow((a-b),2) + pow((b-c),2) + pow((c-a),2);
}

long long int performOperation(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, long long int ans) {
    for(int a =0; a<arr1.size(); a++) {
            long long int x_el = arr1[a];
            long long int y_lessOrEqual, y_greatOrEqual, z_lessOrEqual, z_greatOrEqual;
            auto y_lb = lower_bound(arr2.begin(), arr2.end(), x_el);
            auto y_ub = upper_bound(arr2.begin(), arr2.end(), x_el);
            auto z_lb = lower_bound(arr3.begin(), arr3.end(), x_el);
            auto z_ub = upper_bound(arr3.begin(), arr3.end(), x_el);

            y_lessOrEqual = y_ub == arr2.begin() ? *(y_ub) : *(y_ub - 1);
            y_greatOrEqual = y_lb == arr2.end() ? *(y_lb-1) : *(y_lb);
            z_lessOrEqual = z_ub == arr3.begin() ? *(z_ub) : *(z_ub - 1);
            z_greatOrEqual = z_lb == arr3.end() ? *(z_lb-1) : *(z_lb);

            ans = min(ans, calculateValue(x_el, y_lessOrEqual, z_lessOrEqual));
            ans = min(ans, calculateValue(x_el, y_greatOrEqual, z_lessOrEqual));
            ans = min(ans, calculateValue(x_el, y_lessOrEqual, z_greatOrEqual));
            ans = min(ans, calculateValue(x_el, y_lessOrEqual, z_greatOrEqual));
        }
        return ans;
}

//https://codeforces.com/contest/1337/problem/D
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long int x, y, z;
        cin>>x>>y>>z;
        vector<int> xarr, yarr, zarr;
        for(int i=0; i<x; i++) {
            long long int a;
            cin>>a;
            xarr.push_back(a);
        }
        for(int i=0; i<y; i++) {
            long long int a;
            cin>>a;
            yarr.push_back(a);
        }
        for(int i=0; i<z; i++) {
            long long int a;
            cin>>a;
            zarr.push_back(a);
        }
        sort(xarr.begin(), xarr.end());
        sort(yarr.begin(), yarr.end());
        sort(zarr.begin(), zarr.end());
        long long int ans = LLONG_MAX;

        for(int a =0; a<3; a++) {
            ans = performOperation(xarr, yarr, zarr, ans);
            ans = performOperation(yarr, xarr, zarr, ans);
            ans = performOperation(zarr, yarr, xarr, ans);
        }
        cout<<endl<<ans<<endl;

    }

}