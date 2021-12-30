#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/burst-balloons/
//hARD nice question to build understanding of mcm

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}

	vector<int> modified_arr(n+2);
	modified_arr[0] = 1;
	modified_arr[n+1] = 1;
    
    for(int i =0; i<n; i++) {
        modified_arr[i+1] = arr[i];
    }

	vector<vector<int> > maxGain(n+2, vector<int>(n+2, 0));

	for(int len = 1; len<n+1; len++) {
		for(int i = 1; i<=n+1-len; i++) {
			int j= i+len-1;
            for(int k=i; k<=j; k++) {
				maxGain[i][j] = max(maxGain[i][j], maxGain[i][k-1] + maxGain[k+1][j] + modified_arr[i-1]*modified_arr[k]*modified_arr[j+1]);
			}
		}
	}

	cout<<maxGain[1][n];
	
}