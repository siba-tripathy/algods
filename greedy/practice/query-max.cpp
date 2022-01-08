#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://codeforces.com/contest/276/problem/C
//easy
//AC


int main() {
	int n, q;
	cin>>n>>q;
	vector<long long int> arr(n);

	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}

	vector<long long int> query(n, 0);

	for(int i=0; i<q; i++) {
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		query[l]++;
		if (r<n-1) {
			query[r+1]--;
		}
	}

	for(int i =1; i<n; i++) {
		query[i] = query[i] + query[i-1];
	}

	sort(query.begin(), query.end());
	sort(arr.begin(), arr.end());

	long long int ans=0;
	for(int i=0; i<n; i++) {
		ans+= query[i]*arr[i];
	}
    cout<<ans;
}