#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<int> c(n);
	int ans = 0;
	for(int i = 0; i < n; i++) c[i] = min(a[i], b[i]), ans += c[i];
	while(q--) {
		char k;
		int m, l;
		cin >> k >> m >> l;
		if(k == 'A') {
			a[m - 1] = l;
			int num = c[m - 1];
			c[m - 1] = min(a[m - 1], b[m - 1]);
			ans += (c[m - 1] - num);
		}
		else {
			b[m - 1] = l;
			int num = c[m - 1];
			c[m - 1] = min(a[m - 1], b[m - 1]);
			ans += (c[m - 1] - num);
		}
		cout << ans << endl;
	}
}