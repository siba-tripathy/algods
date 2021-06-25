#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fd5e

vector<long long int> getAllCombos(vector<int>& arr) {
    int n = arr.size();

    vector<long long int> possibilities;
    for(long long int mask = 0; mask<(1<<n); mask++) {      //from zero to 2^n -1(as n bits max value is 2^n -1)
        long long int sum = 0;
        for(int i = 0; i<n; i++) {
            if (mask & (1<<i))
                sum+= arr[i];
        }
        possibilities.push_back(sum);
    }
    return possibilities;
}



int getHappyInstances(vector<int>& arr, int h) {
    int n = arr.size();

    vector<int> left(arr.begin(), arr.begin()+n/2);
    vector<int> right(arr.begin()+n/2, arr.end());

    // for (int i =0; i<left.size(); i++) {
    //     cout<<left[i]<<" ";
    // }
    // cout<<endl;
    // for (int i =0; i<right.size(); i++) {
    //     cout<<right[i]<<" ";
    // }
    // cout<<endl;

    vector<long long int> left_combos = getAllCombos(left);
    vector<long long int> right_combos = getAllCombos(right);

    sort(right_combos.begin(), right_combos.end());
    // for (int i =0; i<left_combos.size(); i++) {
    //     cout<<left_combos[i]<<" ";
    // }
    // cout<<endl;
    // for (int i =0; i<right_combos.size(); i++) {
    //     cout<<right_combos[i]<<" ";
    // }
    // cout<<endl;
    long long int ans = 0;
    for(long long int i = 0; i<left_combos.size(); i++) {
        ans += right_combos.end() - lower_bound(right_combos.begin(), right_combos.end(), h - left_combos[i]);
    }
    return ans;

}

int main() {
    int t;
    cin>>t;
    for(int c = 1; c<=t; c++) {
        int n, h;
        cin>>n>>h;
        vector<int> a_shifts(n, 0);
        vector<int> b_shifts(n, 0);

        for(int i =0; i<n; i++) {
            cin>>a_shifts[i];
        }

        for(int i =0; i<n; i++) {
            cin>>b_shifts[i];
        }

        long long int a = getHappyInstances(a_shifts, h);
        long long int b = getHappyInstances(b_shifts, h);
        // cout<<"a="<<a<<"and b="<<b<<endl;
        cout<<"Case #"<<c<<": "<<a*b<<endl;
    }
}