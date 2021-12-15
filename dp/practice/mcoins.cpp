#include<iostream>
#include<vector>

using namespace std;

//https://www.spoj.com/submit/MCOINS/
//AC

void populateWinnerOrLoserPosition(vector<bool>& isWinning, int k, int l) {
	isWinning[1] = true;

	for(int j=2; j<=isWinning.size(); j++) {
		isWinning[j] = !(isWinning[j-1] && (j-k>=0 ? isWinning[j-k] : true) && (j-l>=0 ? isWinning[j-l] : true));
	}
}

int main() {
	int k, l, m;
	cin>>k>>l>>m;
	vector<int> coinSizes(m);
	for(int i=0; i<m; i++) {
		cin>>coinSizes[i];
	}
	vector<bool> isWinning(1000001, false);

    populateWinnerOrLoserPosition(isWinning, k, l);
	for(int i =0; i<m; i++) {
		if (isWinning[coinSizes[i]] == true){
			cout<<"A";
		} else {
			cout<<"B";
		}
	}

}