#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/perfect-squares
//nice question
//AC

int main() {
	int n;
	cin>>n;
	vector<int> minSquaresSum(n+1, INT_MAX);
	minSquaresSum[0] = 0;
	int numToSquare = 1;
	while(numToSquare*numToSquare <= n) {
		int square = numToSquare*numToSquare;
		for(int i = square; i<=n; i++) {
			minSquaresSum[i] = min(minSquaresSum[i], 1 + minSquaresSum[i-square]);
		}
		numToSquare++;
	}
	cout<<minSquaresSum[n];
}