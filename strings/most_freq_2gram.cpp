#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    map<string, int> freq;
    for (int i=0; i<n-1; i++) {
        string key = s.substr(i, 2);
        if (freq.find(key) == freq.end()) {
            freq.insert({key, 1});
        } else {
            freq[key]++;
        }
    }

    int max_freq_count=0;
    string max_freq_key;
    for(map<string, int>::iterator i = freq.begin(); i!=freq.end(); i++) {
        if (max_freq_count < i->second) {
            max_freq_count = i->second;
            max_freq_key = i->first;
        }
    }
    cout<<max_freq_key;
    return 0;
}