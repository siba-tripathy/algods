//https://www.codechef.com/MAY21C/problems/SOLBLTY
#include<iostream>

using namespace std;

int main() {
    int t = 0;
    cin>>t;
    while(t--) {
        int x, a, b;
        cin>>x>>a>>b;
        cout<<(10 * (a + b*(100 - x)))<<endl;
    }
    return 0;
}