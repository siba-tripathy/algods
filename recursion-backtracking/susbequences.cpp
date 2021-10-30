#include<iostream>
#include<algorithm>
#include<vector>

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

//optimize by avoiding [string concact(o(n)) and substr]and using backtracking with just a single variable
//uosing vectors are push_back and pop_back are efficient than string concat and substr
//not optimizing for repeatations
void prnintSubsequences_op(string &str, vector<char> &current, int fixed) {
    if (fixed == str.size()-1) {
        for(char x: current) {
            cout<<x;
        }
        cout<<endl;
        return;
    }
    prnintSubsequences_op(str, current, fixed+1);
    current.push_back(str[fixed+1]);   //mutate the vector
    prnintSubsequences_op(str, current, fixed+1);
    current.pop_back();                //recover the answer vector for next recursive call
}


int main() {
    string s = "abc";
    //prnintSubsequences(s, "");
    vector<char> ans = vector<char>(0);
    prnintSubsequences_op(s, ans, -1);
}