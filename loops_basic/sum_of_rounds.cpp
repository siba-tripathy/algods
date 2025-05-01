#include<bits/stdc++.h>

using namespace std;

// CF : AC : https://codeforces.com/contest/1352/problem/A

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int dig_place=0;
        vector<int> summands;
        while(n>0) {
            int last_dig = n%10;
            if (last_dig>0) {
                summands.push_back(last_dig * pow(10, dig_place));
            }
            dig_place++;
            n/=10;
        }
        cout<<summands.size()<<endl;
        for (int i=0; i<summands.size(); i++) {
            cout<<summands[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}