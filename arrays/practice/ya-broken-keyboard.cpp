#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

//https://codeforces.com/contest/1272/problem/C
//AC - easy - just umap impl

int main() {
	int n, a;
	cin>>n>>a;
	string s;
	cin>>s;
	unordered_map<char, bool> isAllowed;

	for(int i=0; i<a; i++) {
		char c;
		cin>>c;
		isAllowed[c]=true;
	}

	int lastBreak=-1;
	if(isAllowed.find(s[0])==isAllowed.end()) {
		lastBreak=0;
	}
	long long int ans=0;
	for(int i=1; i<n; i++) {
		if(isAllowed.find(s[i]) == isAllowed.end()) {
			long long int subLength = (long long int)(i-lastBreak-1);
			ans+= subLength*(subLength+1)/2;
			lastBreak = i;
		} else if(i==n-1) {
			long long int subLength = (long long int)(i-lastBreak);
			ans+= subLength*(subLength+1)/2;
        }
	}
	cout<<ans;

}