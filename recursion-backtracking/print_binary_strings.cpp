#include<iostream>
#include<vector>

using namespace std;

//Q: given n, print all the binary strings of size n that donot have any consecutive 1s 

void printBinaryStrings(int numberOfRemainingBits, string stringSoFar) {
    if(numberOfRemainingBits == 0) {
        cout<<stringSoFar<<endl;
        return;
    }

    if(stringSoFar[stringSoFar.length()-1] == '1') {
        stringSoFar.append("0");
        printBinaryStrings(numberOfRemainingBits-1, stringSoFar);
    }
    else {
        string newStringAppended0 = stringSoFar;
        string newStringAppended1 = stringSoFar;
        newStringAppended0.append("0");
        newStringAppended1.append("1");
        printBinaryStrings(numberOfRemainingBits-1, newStringAppended0);
        printBinaryStrings(numberOfRemainingBits-1, newStringAppended1);
    }
}

int main() {
    int n = 3;
    printBinaryStrings(n, "");
    return 0;
}