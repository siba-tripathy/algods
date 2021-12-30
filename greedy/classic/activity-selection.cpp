#include<iostream>
#include<vector>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	return a.second<b.second;
}

int main() {
	int n;
	cin>>n;
	vector<pair<int, int> > arr(n);

	for(int i =0; i<n; i++) {
		cin>>arr[i].first;
		cin>>arr[i].second;
	}

	sort(arr.begin(), arr.end(), compare);
	int ans = 1;
	int lastEnd = arr[0].second;
	for(int i =1; i<n; i++) {
		if(arr[i].first >= lastEnd) {
			ans++;
			lastEnd = arr[i].second;
		}
	}

	cout<<ans;
}