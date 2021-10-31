#include<iostream>
#include<math.h>

using namespace std;

//https://www.hackerrank.com/challenges/the-power-sum/problem
int findIfSumSquarePossible(int x, int n, int currentSum, int currentNumber) {
    if (currentNumber == x || currentSum + pow(currentNumber, n) > x) {
        return 0;
    } else if (currentSum + pow(currentNumber, n) == x) {
        return 1;
    } else {
        int possibilitiesIfIncludeCurrentNumber = findIfSumSquarePossible(x, n, currentSum + pow(currentNumber, n), currentNumber+1);
        int possibilitiesIfNotIncludedCurrentNumber = findIfSumSquarePossible(x, n, currentSum, currentNumber+1);
        return possibilitiesIfIncludeCurrentNumber + possibilitiesIfNotIncludedCurrentNumber;
    }
}

int main() {
    int x,n;
    cin>>x>>n;
    cout<<findIfSumSquarePossible(x, n, 0, 1);
}