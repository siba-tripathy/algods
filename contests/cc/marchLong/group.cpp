#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        //cout<<s<<endl;
        //cout<<s.length()<<endl;
        bool isOne = false;
        int ans = 0;
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '1') {
                isOne = true;
                //cout<<endl<<"1 found at: "<<i<<endl;
            } else {
                if (isOne == true) {
                    //cout<<endl<<"0 found at: "<<i<<endl;
                    ans++;
                    isOne = false;
                }
            }
        }
        if (isOne == true)
            ans++;
        cout<<ans<<endl;
    }
}