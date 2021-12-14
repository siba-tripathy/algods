#include<iostream>
#include<vector>

using namespace std;

int getMinHealthNeeded(vector<vector<int> >& dungeon) {
	int m=dungeon.size();
	int n=dungeon[0].size();
	vector<vector<int> > minHealthNeeded(m, vector<int>(n, INT_MAX));


	for(int i = m-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
            int minHealth = INT_MAX;
            if (j<n-1) {
			    minHealth =  min(minHealth, minHealthNeeded[i][j+1] - dungeon[i][j]);
            }
            if (i<m-1) {
                minHealth =  min(minHealth, minHealthNeeded[i+1][j] - dungeon[i][j]);
            }
            if(minHealth == INT_MAX) {
                minHealth = 1-dungeon[i][j];
            }
            minHealthNeeded[i][j] = max(1, minHealth);
		}
	}

	return minHealthNeeded[0][0];
}

int main() {
	int m, n;
	cin>>m>>n;
	vector<vector<int> > dungeon(m, vector<int>(n));
	for(int i = 0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>dungeon[i][j];
		}
	}

	cout<<getMinHealthNeeded(dungeon);

}