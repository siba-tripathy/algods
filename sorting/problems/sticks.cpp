//https://www.codechef.com/SSWK01/problems/SSWK01C
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    cout<<arr.size()<<endl;
    for(int k=0; k<n-1;k++) {
        if (arr[k+1] != arr[k]) {
            cout<<n-1-k<<endl;
        }
    }

    return 0;
}
