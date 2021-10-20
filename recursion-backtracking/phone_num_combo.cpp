#include<iostream>
#include<vector>

using namespace std;

void printAllCombos(string number, int digitIndex, string numberTillNow) {
    if (digitIndex==number.size()) {
        cout<<numberTillNow<<endl;
        return;
    }
    switch(number[digitIndex]) {
        case '2': {
            printAllCombos(number, digitIndex+1, numberTillNow+'a');
            printAllCombos(number, digitIndex+1, numberTillNow+'b');
            printAllCombos(number, digitIndex+1, numberTillNow+'c');
            break;
        }
        case '3': {
            printAllCombos(number, digitIndex+1, numberTillNow+'d');
            printAllCombos(number, digitIndex+1, numberTillNow+'e');
            printAllCombos(number, digitIndex+1, numberTillNow+'f');
            break;
        }
        case '4': {
            printAllCombos(number, digitIndex+1, numberTillNow+'g');
            printAllCombos(number, digitIndex+1, numberTillNow+'h');
            printAllCombos(number, digitIndex+1, numberTillNow+'i');
            break;
        }
        case '5': {
            printAllCombos(number, digitIndex+1, numberTillNow+'j');
            printAllCombos(number, digitIndex+1, numberTillNow+'k');
            printAllCombos(number, digitIndex+1, numberTillNow+'l');
            break;
        }
        case '6': {
            printAllCombos(number, digitIndex+1, numberTillNow+'m');
            printAllCombos(number, digitIndex+1, numberTillNow+'n');
            printAllCombos(number, digitIndex+1, numberTillNow+'o');
            break;
        }
        case '7': {
            printAllCombos(number, digitIndex+1, numberTillNow+'p');
            printAllCombos(number, digitIndex+1, numberTillNow+'q');
            printAllCombos(number, digitIndex+1, numberTillNow+'r');
            printAllCombos(number, digitIndex+1, numberTillNow+'s');
            break;
        }
        case '8': {
            printAllCombos(number, digitIndex+1, numberTillNow+'y');
            printAllCombos(number, digitIndex+1, numberTillNow+'u');
            printAllCombos(number, digitIndex+1, numberTillNow+'v');
            break;
        }
        case '9': {
            printAllCombos(number, digitIndex+1, numberTillNow+'w');
            printAllCombos(number, digitIndex+1, numberTillNow+'x');
            printAllCombos(number, digitIndex+1, numberTillNow+'y');
            printAllCombos(number, digitIndex+1, numberTillNow+'z');
            break;
        }
    }
}

int main() {
    string number;
    cin>>number;

    printAllCombos(number, 0, "");

}