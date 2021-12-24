#include<iostream>
#include<vector>

using namespace std;


//AC: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ : easy
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}

	int maxProfit = 0;
	for(int i = 1; i<n; i++) {
		if(arr[i-1]<arr[i]) {
			maxProfit += arr[i]-arr[i-1];
		}
	}
	cout<<maxProfit;

}