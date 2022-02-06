#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> stones(n);
	int sum = 0;
	for(int i=0; i<n; i++) {
		cin>>stones[i];
		sum+=stones[i];
	}

	int half = sum/2;

	vector<vector<int> > isPossible(n+1, vector<int>(half+1, 0));

	for(int i=0; i<n+1; i++) {
		isPossible[i][0] = 1;
	}

	for(int i =1; i<n+1; i++) {
		for(int j = 1; j<half+1; j++) {
			//not pick
			int p1 = isPossible[i-1][j];
			//pick
			int p2 = 0;
			if(stones[i-1] <= j) {
				p2 = isPossible[i-1][j-stones[i-1]];
			}
			isPossible[i][j] = p1 | p2;
		}
	}

	int maxSum = 0;
	for(int j=1; j<half+1; j++) {
		if(isPossible[n][j] != 0) {
			maxSum = j;
		}
	}

	cout<<sum - 2*maxSum;

}