#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define int long long
int fa[maxn], sz[maxn], c[maxn];
int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if(rx == ry) return ;
    sz[rx] += sz[ry];
    fa[ry] = rx;
}

signed main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) fa[i] = i;
    while(q--) {
        int op, u, v;
        cin >> op;
        if(op == 1) {
            cin >> u >> v;
            merge(u, v);
        }else if(op == 2) {
            cin >> u;
            int fau = find(u);
            if(c[u] == 0) sz[fau]++;
            else sz[fau]--;
            c[u] ^= 1;
        }else {
            cin >> u;
            int fau = find(u);
            if(sz[fau] > 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}