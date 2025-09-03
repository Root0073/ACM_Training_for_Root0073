#include <bits/stdc++.h>
#define int long long
using namespace std;
#define inf 0x3f3f3f3f3f3f3f3f
struct node {
	int r, c;
	node operator + (const node& a) {return node{r + a.r, c + a.c};};
	node operator - (const node& a) {return (node){r - a.r, c - a.c};};
};
signed main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	node t, a;
	cin >> t.r >> t.c >> a.r >> a.c;
	int n, m, l;
	cin >> n >> m >> l;
	t = t - a;//把他变成相对距离
	vector<pair<char, int>> pa, pt;
	int now = 0;
	for(int i = 0; i < m; i++) {
		int num;
	 	char k;
		cin >> k >> num;
		now += num;
		pt.push_back(make_pair(k, now));
	}
	now = 0;
	for(int i = 0; i < l; i++) {
		int num;
		char k;
		cin >> k >> num;
		now += num;
		pa.push_back(make_pair(k, now));
	}
	map<char, node> mp;
	mp['U'] = (node){-1, 0};
	mp['D'] = (node){1, 0};
	mp['L'] = (node){0, -1};
	mp['R'] = (node){0, 1};
	int ti = 0, ai = 0;
	auto check = [&](int a, int b) -> int {//用于检查
		if(a == 0) return (b == 0) ? inf : -1;
		if(a < 0) a = -a, b = -b;
		if(-b % a != 0) return -1;
		return -b / a; 
	};
	now = 0;
	int ans = 0;
	while(ai < l && ti < m) {
		int nxt = min(pt[ti].second, pa[ai].second);
		int w = nxt - now; 
		node dt = mp[pt[ti].first] - mp[pa[ai].first];
		int rx = check(dt.r, t.r);
		int cx = check(dt.c, t.c);
		if(rx != -1 && cx != -1) {//如果没有无解
			if(rx == inf && cx == inf) ans += w;
			else if(rx == inf || cx == inf) {
				int f = (rx == inf ? cx : rx);
				if(0 < f && f <= w) ans += 1;
			}
			else if(rx == cx && 0 < rx && rx <= w) ans += 1;
		}
		t.r += w * dt.r;
		t.c += w * dt.c;
		if(nxt == pt[ti].second) ti++;
		if(nxt == pa[ai].second) ai++;
		now = nxt;
	}
	cout << ans << endl;
}