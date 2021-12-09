#include<iostream>
#include<vector>

using namespace std;

void getForwardGainsFromK(vector<int>& arr, vector<int>& forwardGains, int k) {
	forwardGains[k] = 0;
    if(arr.size() == 1) {
        return;
    }
    forwardGains[k+1] = arr[k+1];
    if(arr.size() == 2) {
        return;
    }
	for(int i = k+2; i<arr.size(); i++) {
		forwardGains[i] = arr[i] + max(forwardGains[i-1], forwardGains[i-2]);
	}
}

void getForwardGainsFromOne(vector<int>& arr, vector<int>& forwardGainsFromOne) {
	forwardGainsFromOne[0] = 0;
    if(arr.size() == 1) {
        return;
    }
    forwardGainsFromOne[1] = arr[1];
    if(arr.size() == 2) {
        return;
    }
	for(int i = 2; i<arr.size(); i++) {
		forwardGainsFromOne[i] = arr[i] + max(forwardGainsFromOne[i-1], forwardGainsFromOne[i-2]);
	}
}

int main() {
	int n, k;
	cin>>n>>k;
	vector<int> arr = vector<int>(n, 0);
	for(int i =0; i<n; i++) {
		cin>>arr[i];
	}
    k--;
	vector<int> forwardGainsFromOne = vector<int>(n, 0);
	vector<int> forwardGainsFromK = vector<int>(n, 0);

	getForwardGainsFromOne(arr,forwardGainsFromOne);
	getForwardGainsFromK(arr, forwardGainsFromK, k);

	int maxScore = 0;
	for(int i = k; i<n; i++) {
		maxScore = max(maxScore, forwardGainsFromK[i]+forwardGainsFromOne[i]-arr[i]+arr[0]);
	}
	cout<<maxScore;
}