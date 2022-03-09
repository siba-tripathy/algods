#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//checked same as pulkit - runs well on ex input

int find_parity(string s) {
    int parity = 0;
    for(int i=0; i<s.size(); i++) {
        int ch = s[i] - 'a';
        parity ^= 1<<ch;
    }
    return parity;
}

int main() {
    
    vector<string> strings{"abababcabcc", "xyxyxx", "p"};
    int n=strings.size();

    unordered_map<int, int> parity_freq;

    int ans=0;
    for(int i=0; i<n; i++) {
        int cur_string_parity = find_parity(strings[i]);
        //condition 1
        ans+=parity_freq[cur_string_parity];
        //condition 2
        for(int i=0; i<26; i++) {
            ans+= parity_freq[ (1<<i) ^ cur_string_parity];
        }
        parity_freq[cur_string_parity]++;
        
    }
    cout<<ans;
}