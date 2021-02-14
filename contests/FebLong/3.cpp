#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool lesser(string a, string b) {
    string a_half = a.substr(6, 2);
    string b_half = b.substr(6, 2);

    // cout<<"a half = "<<a_half<<" and b half = "<< b_half<<endl;
    if (a_half < b_half) {
        return true;
    } else if (a_half > b_half) {
        return false;
    }

    int a_hr = stoi(a.substr(0, 2));
    int b_hr = stoi(b.substr(0, 2));
    if (a_hr == 12)
        a_hr = 0;
    if(b_hr == 12)
        b_hr = 0;


    // cout<<"a hr = "<<a_hr<<" and b hr = "<< b_hr<<endl;
    if (a_hr < b_hr) {
        return true;
    } else if (a_hr > b_hr) {
        return false;
    }

    int a_min = stoi(a.substr(3, 2));
    int b_min = stoi(b.substr(3, 2));

    // cout<<"a min = "<<a_min<<" and b min = "<< b_min<<endl;
    if (a_min < b_min) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int t;
    string input;
    getline(cin, input);
    t= stoi(input);
    
    while(t--) {
        int n;
        char arr[100];
        string party_time, ans="";
        getline(cin, party_time);
        // cout<<"party time= "<<party_time;
        getline(cin, input);
        n = stoi(input);
        for(int i=0; i<n; i++) {
            string s;
            getline(cin, s);
            string in_time = s.substr(0, 8);
            // cout<<"in time"<<in_time<<endl;
            string out_time = s.substr(9, 8);
            // cout<<"out time"<<out_time<<endl;
            if ((lesser(in_time, party_time) || in_time == party_time) && (lesser(party_time, out_time) || party_time == out_time)) {

                // cout<<(lesser(in_time, party_time))<<endl;
                // cout<<(lesser(party_time, out_time))<<endl;
                ans+="1";
            } else {
                ans+= "0";
            }
        }
        cout<<ans<<endl;
    }
}

