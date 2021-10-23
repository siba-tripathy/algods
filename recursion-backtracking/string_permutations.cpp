#include<iostream>

using namespace std;

void printAllPermutations(string input, string ans) {
    if(input.empty()) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<input.length(); i++) {
        string next = input;
        next.erase(next.begin()+i);
        printAllPermutations(next, ans+input[i]);
    }
}

int main() {
    string str;
    cin>>str;
    printAllPermutations(str, "");
}