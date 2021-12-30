#include<iostream>
#include<vector>

using namespace std;


//https://www.codechef.com/problems/RAMDEV
//not AC
//but same as sanket code and passing sample test cases


int main() {
	int l, b, n;
	cin>>l>>b>>n;
	vector<int> ln(n);
	vector<int> bn(n);
	for(int i = 0; i<n; i++) {
		cin>>ln[i]>>bn[i];
	}

	int ans = 0;
	for(int i = 0; i<n; i++) {
		ans += max((ln[i]/l*bn[i]/b), (ln[i]/b*bn[i]/l));
	}
	cout<<ans;
}