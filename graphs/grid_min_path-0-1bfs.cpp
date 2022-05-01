#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

//https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
//AC
//good question - understand 0-1 BFS, state of queue at any point in BFS
//0-1 bfs article: https://codeforces.com/blog/entry/22276
//read relaxation - dist is later decreased 

using namespace std;

class node {
	public:
		int x;
		int y;
		int dist;

	node(int a, int b, int c) {
		x=a;
		y=b;
	    dist=c;
	}
};

vector<pair<int, int> > directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<vector<int> >& grid, int n, int m) {
	int ans = 0;
	deque<node> q;
	q.push_back(node(0, 0, 0));
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	visited[0][0] = true;

	while(!q.empty()) {
		node top = q.front();
		q.pop_front();
		int curi = top.x;
		int curj = top.y;
		int cur_dist = top.dist;

        visited[curi][curj] = true;                 //have to mark visited at pop time, as in 0-1 bfs we can have the same node i,j in the queue multiple times
        //in case when relaxation happens, the node who was visited with a +1 dist, might now be relaxed to get visited by +0 dist
        cout<<curi<<curj<<cur_dist<<endl;

		if (curi == n-1 && curj == m-1) {
			ans = top.dist;
			break;
		}

		for(pair<int, int> dir : directions) {
			int nbi = curi + dir.first;
			int nbj = curj + dir.second;
			if ((nbi <n && nbi >=0 && nbj <m && nbj >=0) && !visited[nbi][nbj]) {
				if ((grid[curi][curj] == 1 && dir.first == 0 && dir.second == 1) || 
					(grid[curi][curj] == 2 && dir.first == 0 && dir.second == -1) ||
					(grid[curi][curj] == 3 && dir.first == 1 && dir.second == 0) ||
					(grid[curi][curj] == 4 && dir.first == -1 && dir.second == 0)) {
					q.push_front(node(nbi, nbj, top.dist));
				} else {
					q.push_back(node(nbi, nbj, top.dist + 1));
				}
			}
		}
	}
	return ans;
}

int main() {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > grid(n, vector<int>(m, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>grid[i][j];
		}
	}
    cout<<bfs(grid, n, m);
	return 0;
}