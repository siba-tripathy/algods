#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://www.codechef.com/problems/HW2C
//AC

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.first != y.first) {
		return x.first < y.first;
	} else {
		return x.second < y.second;
	}
}

int main() {
	int n;
	cin>>n;
	vector<pair<int, int> > arr(n);
	for(int i = 0; i<n; i++) {
		cin>>arr[i].first;
		cin>>arr[i].second;
	}

	sort(arr.begin(), arr.end(), compare);

	int last = arr[0].second;
	for(int i = 1; i<n; i++) {
		if (last > arr[i].second) {
			last = arr[i].first;
		} else {
			last = arr[i].second;
		}
	}
	cout<<last;
}