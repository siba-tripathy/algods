#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

//we wont need to cover all components - just single bfs from start
//preferring bfs as we wont do consuing recursion there, we want to do just one traversal
bool possible(int start, int target, int rank, vector<vector<int> >& adj) {
	
	queue<int> q;
	vector<bool> visited(adj.size(), false);
	
	q.push(start);
	visited[start] = true;

	while(!q.empty()) {

		int cur = q.front();
		//cout<<cur<<" ";
		q.pop();

		for(pair<int, int> nb : adj[cur]) {
			if(!visited[nb.first] && nb.second <= rank) {				//enque the not visited neighbours for later utilisation - only visit those whole th <= rank
				q.push(nb.first);
				visited[nb.first]=true;           
			}
		}
	}

	return visited[target];
}

int main() {
	int n,m, source, dest; 
	cin>>n>>m>>source>>dest;
	vector<vector<pair<int, int> > > adj(n+1);
	for(int i=0; i<m; i++) {
		int x, y, th;    //threshold
		cin>>x>>y>>th;
		adj[x].push_back({y, th});        //directed graph - not bidirectional
	}
	int beg = 1, end =10000;
	int min_rank = -1;               //for cases when its impossible, not path exists
	while(beg<end) {
		int mid = (beg+end)/2;
		if (possible(source, dest, mid, adj) && possible(dest, source, mid, adj)) {
			min_rank = mid;
			end = mid-1;
		} else {
			beg = mid+1;
		}
	}
	cout<<min_rank<<endl;
	return 0;
}