#include<iostream>
#include<vector>

using namespace std;

//simple-adhoc https://leetcode.com/problems/best-time-to-buy-and-sell-stock
//AC
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}

	int min = arr[0];
	int maxProfit = 0;
	for(int i = 1; i<n; i++) {
		if(arr[i]<min) {
			min=arr[i];
		} else {
			maxProfit = max(maxProfit, arr[i] - min);
		}
	}
	cout<<maxProfit;

}