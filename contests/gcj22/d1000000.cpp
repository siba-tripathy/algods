#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;


int main() {
	int t;
	cin>>t;
	for(int turn=1; turn<=t; turn++) {
		int n;
		cin>>n;
		vector<int> val(n);
        for(int i=0; i<n; i++) {
        	cin>>val[i];
        }
        sort(val.begin(), val.end());
        int deficit = 0;
        for(int i=1; i<=n; i++) {
        	if(val[i-1]<i) {
        		deficit++;
        	}
        }
        cout<<"Case #"<<turn<<": "<<n-deficit<<endl;
	}
	return 0;
}