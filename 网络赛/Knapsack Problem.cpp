#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
struct node {
	int u;
	pair<int, int> v;
	friend bool operator < (node a, node b) {
		return a.v > b.v;
	}
};
void solve() {
	int n, m, V, t;
	cin >> n >> m >> V >> t;
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back({v, d});
		g[v].push_back({u, d});
	}
	vector<pair<int, int>> dis(n + 1, pair{inf, inf});
	dis[t] = {1, 0};
	priority_queue<node> pq;
	vector<bool> vis(n + 1, false);
	pq.push({t, {1, 0}});
	while(!pq.empty()) {
		auto [now, p] = pq.top();
		pq.pop();
		if(vis[now]) continue;
		vis[now] = true;
		for(int i = 0; i < g[now].size(); i++) {
			int v = g[now][i].first, w = g[now][i].second;
			int b = dis[now].second + w;
			int c = dis[now].first;
			if(b > V) {
				c++;
				b = w;
			}
			if(dis[v] > pair{c, b}) {
				dis[v] = pair{c, b};
				pq.push({v, dis[v]});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(dis[i].first == inf) cout << -1 << " ";
		else cout << dis[i].first << " ";
	}
}
signed main() {
	int t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}