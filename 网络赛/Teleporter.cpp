#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
struct node {
	int u, dis;
	friend bool operator < (node a, node b) {
		return a.dis > b.dis;
	}
};
signed main() {
	int n ,m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<pair<int, int>> e;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e.push_back({u, v});
	}
	priority_queue<node> pq;
	vector<vector<int>> dis(n + 1, vector<int>(n + 1, inf));
	pq.push({1, 0});
	dis[1][0] = 0;
	auto cul = [&](int i) -> void {//这里就相当于一个裸的最短路
		while(!pq.empty()) {
			int u = pq.top().u, d = pq.top().dis;
			pq.pop();
			for(int j = 0; j < g[u].size(); j++) {
				int v = g[u][j].first, w = g[u][j].second;
				if(dis[v][i] > d + w) {
					dis[v][i] = d + w;
					pq.push({v, dis[v][i]});
				}
			}
		}
	};
	auto update = [&](int N) -> void {//这一块是去计算层和层之间的传递
		if(N) {
			for(int i = 0; i < e.size(); i++) {
				int u = e[i].first, v = e[i].second;
				dis[u][N] = min(dis[u][N], dis[v][N - 1]);
				dis[v][N] = min(dis[v][N], dis[u][N - 1]);
			}
			for(int i = 1; i <= n; i++) {
				if(dis[i][N] < dis[i][N - 1]) {
					pq.push({i, dis[i][N]});//di算法的本质：因为这一条边的dis值改变了所以将他存进pq里用他来
				}
				dis[i][N] = min(dis[i][N], dis[i][N - 1]);
			}
		}
		int res = 0;
		cul(N);
		for(int i = 1; i <= n; i++) {
			res += dis[i][N];
		}
		cout << res << endl;
	};
	for(int i = 0; i <= n; i++) update(i);
}