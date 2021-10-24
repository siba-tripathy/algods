#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// this method will print all permutations(Wrong), but if input string has duplicate chars, then sequences can be repeated
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

//most optimized solution - Very imp to see that backtracknig(recovering aspect) is useful.
void printAllPermutations_optimized(string input, int i) {
    if(i == input.length()-1) {
        cout<<input<<endl;
        return;
    }
    vector<bool> visited = vector<bool>(26, false);
    for(int j=i; j<input.length(); j++) {
        if (!visited[input[j]-'a']) {
            visited[input[j]-'a'] = true;
            swap(input[j], input[i]);     //take each element to the ith place
            printAllPermutations_optimized(input, i+1);
            swap(input[j], input[i]);     //swap again to recover input string, so that next loop/ next child recursion has right input
        }
    }
}


int main() {
    string str;
    cin>>str;
    //printAllPermutations(str, "");
    printAllPermutations_optimized(str, 0);
}