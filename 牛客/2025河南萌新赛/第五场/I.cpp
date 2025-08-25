#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define int long long
int n, m, q, s;
int d[maxn], anc[maxn][20], dis[maxn], a[maxn];
vector<int> g[maxn];
void dfs(int u, int fa) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == fa) continue;
		dis[v] = dis[u] + a[v];
        d[v] = d[u] + 1;
        anc[v][0] = u;
        dfs(v, u);
    }
}
void init() {
    for(int j = 1; j <= 18; j++) {
        for(int i = 1; i <= n; i++) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
}
int LCA(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    for(int i = 18; i >= 0; i--) {
        if(d[anc[u][i]] >= d[v]) u = anc[u][i];//类似于二进制分解
    }
    if(u == v) return u;
    for(int i = 18; i >= 0; i--) {
        if(anc[u][i] != anc[v][i]) {//尽可能逼近lca
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}
signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dis[1] = a[1];
    d[1] = 1;
    dfs(1, 0);
    init();
    cin >> q;
    while(q--) {
        int l;
        cin >> l;
        int k, b;
        cin >> k >> b;
        int aa = LCA(k, b);
        //for(int i = 1; i <= n; i++) cout << dis[i] << " ";
        cout << dis[aa] + dis[k] - dis[aa] + dis[b] - dis[aa] << endl;
    }
    return 0;
}