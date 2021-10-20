#include<iostream>
#include<algorithm>

using namespace std;
//print all subsequences of a string
void prnintSubsequences(string str, string current) {
    //cout<<"str = "<<str<<" and current = "<<current<<endl;
    if (str.empty()) {
        cout<<current<<endl;
        return;
    }
    prnintSubsequences(str.substr(1, str.length()-1), current);
    prnintSubsequences(str.substr(1, str.length()-1), current.append(str.substr(0, 1)));
    
}

int main() {
    string s = "abc";
    prnintSubsequences(s, "");
}