#include<bits/stdc++.h>

using namespace std;

// CF : V Easy  : Good for case transition method knowledge : https://codeforces.com/problemset/problem/112/A

int main() {
    string a, b;
    cin>>a>>b;

    for(int i=0; i<a.size(); i++) {
        if (toupper(a[i]) > toupper(b[i])) {
            cout<<1;
            return 0;
        } else if (toupper(a[i]) < toupper(b[i])) {
            cout<<-1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}