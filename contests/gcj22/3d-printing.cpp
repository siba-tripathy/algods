#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;


int main() {
	int t;
	cin>>t;
	for(int turn=1; turn<=t; turn++) {

		vector<vector<int> > col(3, vector<int>(4));
        for(int i=0; i<3; i++) {
        	for(int j=0; j<4; j++) {
        		cin>>col[i][j];
        	}
        }

        vector<int> lows(4);
        int sum = 0;
        for(int j=0; j<4; j++) {
        	lows[j] = min({col[0][j], col[1][j], col[2][j]});
        	sum+=lows[j];
        }
        
        if(sum < 1000000) {
        	cout<<"Case #"<<turn<<": IMPOSSIBLE"<<endl;
        } else {
        	cout<<"Case #"<<turn<<": ";
        	sum=0;
        	for(int i=0; i<4; i++) {
        		if(sum > 1000000) {
        			cout<<0<<" ";
        		} else if(sum+lows[i] > 1000000) {
        			cout<<1000000 - sum<<" ";
        			sum = 1000000;
        		} else {
        			sum+=lows[i];
        			cout<<lows[i]<<" ";
        		}
        	}
        	cout<<endl;
        }
	}
	return 0;
}