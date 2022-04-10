#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;


int main() {
	int t;
	cin>>t;
	for(int turn=1; turn<=t; turn++) {

		int r, c;
		cin>>r>>c;
		cout<<"Case #"<<turn<<":"<<endl;
        for(int i=0; i<r*2+1; i++) {
        	for(int j=0; j<c*2+1; j++) {
        		if (i<2 && j<2) {
        			cout<<".";
        		} else if (i%2==0) {
        			if (j%2==0) {
        				cout<<"+";
        			} else {
        				cout<<"-";
        			}
        		} else {
        			if (j%2==0) {
        				cout<<"|";
        			} else {
        				cout<<".";
        			}
        		}
        	}
        	cout<<endl;
        }
	}
	return 0;
}