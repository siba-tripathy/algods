#include<iostream>

using namespace std;

//given n, print all the valid braces sequences that you can build
void printAllBraces(int size, int balance, string stringTillNow) {
    if(size == 0) {
        if (balance == 0) {
            cout<<stringTillNow<<endl;
        }
        return;
    }
    if (balance >0 ) {
        printAllBraces(size-1, balance+1, stringTillNow + '(');
        printAllBraces(size-1, balance-1, stringTillNow + ')');
    } else {
        printAllBraces(size-1, balance+1, stringTillNow + '(');
    }

}

int main() {
    int n;
    cin>>n;
    printAllBraces(2*n, 0, "");
}