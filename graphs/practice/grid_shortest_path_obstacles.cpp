#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination
// V.Good question - common pattern
// AC
// hint at end

class node {
	public:
		int x;
		int y;
		int k;

	node(int a, int b, int c) {
		x=a;
		y=b;
		k=c;
	}
};

vector<pair<int, int> > directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int startx, int starty, vector<vector<int> >& val, vector<vector<vector<int> > >& min_dist, int k) {
	
	int n = val.size();
	int m = val[0].size();
	node a = node(startx, starty, k);

	queue<node> q;
	q.push(a);
	min_dist[startx][starty][k] = 0;

	while(!q.empty()) {
		node front = q.front();
		q.pop();

		for(pair<int, int> dir : directions) {
			int targetx = front.x+dir.first;
			int targety = front.y+dir.second;
			if (targetx >=0 && targetx <n && targety >= 0 && targety < m) {                 //is it valid - within the matrix
				int rem_k = val[targetx][targety] == 0 ? front.k : front.k-1;
				if (rem_k >=0 && min_dist[targetx][targety][rem_k] == -1) {                 //is it reachable and unvisited
					min_dist[targetx][targety][rem_k] = min_dist[front.x][front.y][front.k] + 1;
                    q.push(node(targetx, targety, rem_k));
				}
			}
		}
	}

	int ans = INT_MAX;
	for(int i=0; i<=k; i++) {                                        //need to check all states from k to 0 (none used -> all used)
		if(min_dist[n-1][m-1][i] != -1) {
			ans = min(ans, min_dist[n-1][m-1][i]);
		}
	}

	return ans == INT_MAX ? -1 : ans;
}

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<int> >val(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>val[i][j];
		}
	}

	vector<vector<vector<int> > > min_dist(n, vector<vector<int> >(m, vector<int>(k+1, -1)));       //-1 means not visited
	cout<<bfs(0, 0, val, min_dist, k);

	return 0;
}




























//state based BFS