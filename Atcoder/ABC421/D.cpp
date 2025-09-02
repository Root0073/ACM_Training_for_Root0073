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
	node t, a;
	cin >> t.r >> t.c >> a.r >> a.c;
	int n, m, l;
	cin >> n >> m >> l;
	t = t - a;
	vector<pair<char, int>> pa, pt;
	for(int i = 0; i < m; i++) {
		int num;
	 	char k;
		cin >> k >> num;
		pt.push_back(make_pair(k, num));
	}
	for(int i = 0; i < l; i++) {
		int num;
		char k;
		cin >> num >> k;
		pa.push_back(make_pair(k, num));
	}
	map<char, node> mp;
	mp['U'] = (node){-1, 0};
	mp['D'] = (node){1, 0};
	mp['L'] = (node){0, -1};
	mp['R'] = (node){0, 1};
}
