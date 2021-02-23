#include<iostream>

using namespace std;

int main() {
    long long int t;
    cin>>t;
    while(t--) {
        long long int p, a, b, c;
        cin>>p>>a>>b>>c;
        long long int wait_a = (p%a)==0 ? 0 : a-(p%a);
        long long int wait_b = (p%b)==0 ? 0 : b-(p%b);
        long long int wait_c = (p%c)==0 ? 0 : c-(p%c);
        cout<<min(min(wait_a, wait_b), wait_c)<<endl;
    }
}