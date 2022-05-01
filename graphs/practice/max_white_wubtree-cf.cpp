#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

//https://codeforces.com/contest/1324/problem/F
//AC
//good question
//hint at end

void dfs_calc_sub_profit(int cur, int par, vector<vector<int> >& adj, vector<int>& val, vector<int>& sub_profit) {
	int profit = val[cur];

	for(int nb : adj[cur]) {
		if(nb != par) {
			dfs_calc_sub_profit(nb, cur, adj, val, sub_profit);
			profit+= max(0, sub_profit[nb]);
		}
	}

	sub_profit[cur] = profit;
}

void dfs_calc_anscestral_max(int cur, int par, vector<vector<int> >& adj, vector<int>& sub_profit, vector<int>& max_profit_ancestral) {

	if(par) {    //not for root
		max_profit_ancestral[cur] += max(0, max_profit_ancestral[par] - max(0, sub_profit[cur]));
	}


	for(int nb : adj[cur]) {
		if(nb != par) {
			dfs_calc_anscestral_max(nb, cur, adj, sub_profit, max_profit_ancestral);
		}
	}

}
 
int main() {
	int n;
	cin>>n;
	vector<int> val(n+1, -1);                      //marking black as -1 as we want white-black, this will simply mean add the values of vertices
	for(int i=1; i<=n; i++) {
		int v;
		cin>>v;
		if(v==1) {
			val[i] = v;
		}
	}

	vector<vector<int> > adj(n+1);

	for(int i=0; i<n-1; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> sub_profit(n+1, 0);
	dfs_calc_sub_profit(1, 0, adj, val, sub_profit);
	
	vector<int> max_profit_ancestral(sub_profit.begin(), sub_profit.end());
	dfs_calc_anscestral_max(1, 0, adj, sub_profit, max_profit_ancestral);

    for(int i=1; i<=n; i++) {
        cout<<max_profit_ancestral[i]<<" ";
    }
    cout<<endl;
	return 0;
}






















//hint: in-put dp