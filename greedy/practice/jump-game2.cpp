#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> dp(n, 1001); //max value that can be
	dp[n-1] = 0; //last slot no more jump
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}

	for(int i=n-2; i>=0; i--) {
		int jumpMax = arr[i];
		for(int j=i+1; j<=i+jumpMax && j<=n-1; j++) {
			dp[i] = min(dp[i], 1 + dp[j]);
		}
	}

	cout<<dp[0]<<endl;
}