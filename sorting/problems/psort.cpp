#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

// https://www.codechef.com/UAPRAC/problems/PSORT3
bool compare(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    if(b.second > a.second) {
        return false;
    } else if (b.second < a.second) {
        return true;
    }
    if (a.first > b.first) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<pair<long long int, long long int>> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i].first;
    }

    for(int i=0; i<n; i++) {
        cin>>arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);

    for (pair<long long int, long long int> x: arr) {
        cout<<x.first<<" "<<x.second<<" ";
    }
    return 0;
}