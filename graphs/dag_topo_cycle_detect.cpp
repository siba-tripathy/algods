#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[100001];
vi adj[100001];
int n, m;
int ans = 0;

void dfs_util(int i, vi &vis)
{
	vis[i] = 1;

	for (pii e : adj[i])
	{
		int j = e.ff, w = e.ss;

		if (!vis[j])
			dfs_util(j, vis);

		dp[i] = max(dp[i], dp[j] + w);
	}

	ans = max(ans, dp[i]);
}

void dfs()
{
	vi vis(n + 1);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs_util(i, vis);

}

void dfs_for_topo(int i, vi &vis, vi &ans)
{
	vis[i] = 1;

	for (int j : adj[i])
		if (!vis[j])
			dfs_for_topo(j, vis, ans);

	ans.pb(i);
}

vi topo_by_dfs()
{
	vi vis(n + 1), ans;

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs_for_topo(i, vis, ans);

	reverse(ans.begin(), ans.end());

	return ans;
}

bool dfs_for_topo_check(int i, vi &vis, vi &ans)
{
	vis[i] = 1;

	for (int j : adj[i])
	{
		if (vis[j] == 0)
		{
			bool poss = dfs_for_topo_check(j, vis, ans);

			if (poss == 0)
				return 0;
		}

		else if (vis[j] == 1)
			return 0;
	}

	vis[i] = 2;
	ans.pb(i);

	return 1;
}

vi topo_by_dfs_check()
{
	vi vis(n + 1), ans;

	bool possible = 1;

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			possible &= dfs_for_topo_check(i, vis, ans);

	reverse(ans.begin(), ans.end());

	return possible ? ans : vi{};
}

vi topo_by_bfs()
{
	vi ans;
	queue<int> q;

	vi in(n + 1);

	for (int i = 1; i <= n; ++i)
		for (int j : adj[i])
			in[j]++;

	for (int i = 1; i <= n; ++i)
		if (in[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		ans.pb(i);

		for (int j : adj[i])
		{
			in[j]--;

			if (in[j] == 0)
				q.push(j);
		}
	}

	return ans.size() < n ? vi{} : ans;
}

int32_t main()
{
	FIO;
	cin >> n >> m;
	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].pb(j);
		// adj[j].pb(i);
	}

	//dfs();

	cout << ans << '\n';
	return 0;
}