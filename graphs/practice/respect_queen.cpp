#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

//https://codeforces.com/problemset/problem/1143/C
//AC - easy - intuition trick

void dfs(int cur, int par, vector<vector<int> >& adj, vector<int>& respect, vector<int>& del) {
	bool any_respect = false;
	for(int nb: adj[cur]) {
		if(nb != par) {
			if (respect[nb] == 0) {
				any_respect = true;
			}
			dfs(nb, cur, adj, respect, del);
		}
	}
	if(respect[cur] == 1 && !any_respect) {
		del.push_back(cur);
	}
	return;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > adj(n+1);
	vector<int> respect(n+1);
	int root;
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		if(x==-1) {
			root = i;
		} else {
		    adj[x].push_back(i);
		    adj[i].push_back(x);
        }
		cin>>respect[i];
	}
	vector<int> del;
	dfs(root, -1, adj, respect, del);
	sort(del.begin(), del.end());
    if (del.empty()) {
        cout<<-1;
    } else {
        for(int x : del) {
	        cout<<x<<" ";
        }
    }
	return 0;
}