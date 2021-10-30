#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/lexicographical-numbers/

void printLexicoNumbers(int& n, int& current) {

    if(current>n) {
        return;
    }
    if (current != 0) {  //not printing 0
        cout<<current<<endl;
    }
    current*=10;
    for(int i = 0; i<=9; i++) {
        if (current+i!=0) { // to stop infinite recursion on 0
            printLexicoNumbers(n, current+=i);
            current-=i;
        }
    }
    current/=10;
}


int main() {
    int n = 29;
    int ans = 0;
    printLexicoNumbers(n, ans);
}