#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, h, x;
    cin>>n>>h>>x;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int max = *max_element(arr.begin(), arr.end());
    if(max >= h - x)
        cout<<"YES";
    else
        cout<<"NO";
}