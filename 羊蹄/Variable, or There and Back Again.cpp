#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<vector<int>> g(n + 1), rg(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	vector<bool> vis1(n + 1, false), vis2(n + 1, false);
	auto dfs1 = [&](auto &dfs1, int u) -> void {
		vis1[u] = true;
		for(int i = 0; i < g[u].size(); i++) {
			if(!vis1[g[u][i]] && a[g[u][i]] != 1) dfs1(dfs1, g[u][i]); 
		}
	};
	for(int i = 1; i <= n; i++) {
		if(a[i] == 1) dfs1(dfs1, i);
	}
	auto dfs2 = [&](auto &dfs2, int u) -> void {
		vis2[u] = true;
		if(a[u] == 1) return ;
		for(int i = 0; i < rg[u].size(); i++) {
			if(!vis2[rg[u][i]]) dfs2(dfs2, rg[u][i]);
		}
	};
	for(int i = 1; i <= n; i++) {
		if(a[i] == 2) dfs2(dfs2, i);
	}
	for(int i = 1; i <= n; i++) {
		if(vis1[i] && vis2[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}