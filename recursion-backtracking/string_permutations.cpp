#include<iostream>
#include<vector>

using namespace std;


// this method will print all permutations, but if input string has duplicate chars, then sequences can be repeated
void printAllPermutationsRepeated(string input, string ans) {
    if(input.empty()) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<input.length(); i++) {
        string next = input;
        next.erase(next.begin()+i);
        printAllPermutationsRepeated(next, ans+input[i]);
    }
}

void printAllPermutations(string input, string ans) {
    if(input.empty()) {
        cout<<ans<<endl;
        return;
    }
    vector<bool> visited = vector<bool>(26, false);
    for(int i=0; i<input.length(); i++) {
        if (!visited[input[i]-'a']) {
            visited[input[i]-'a'] = true;
            string next = input;
            next.erase(next.begin()+i);
            printAllPermutations(next, ans+input[i]);
        }
    }
}


int main() {
    string str;
    cin>>str;
    printAllPermutations(str, "");
}