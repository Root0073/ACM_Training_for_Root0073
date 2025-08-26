#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
//思路：将问题转化为求最小的m使得k^m | n!
//Legendre公式 n!中某个质数指数的计算方法 v_p = sigma(i, 1 - inf) [n / (p ^ i)]
int main() {
    int n, k;
	cin >> n >> k;
	vector<pair<int, int>> p;
	for(int i = 2; i <= k / i; i++) {//对k进行质因数分解
		if(k % i == 0) {
			int cnt = 0;
			while(k % i == 0) {
				cnt++;
				k /= i;
			}
			p.push_back({i, cnt});
		}
	}
	if(k > 1) p.push_back({k, 1});
	int ans = inf;
	for(auto tmp : p) {
		int d = tmp.first, v = tmp.second;
		int s = 0, x = n;
		while(x) {
			s += x / d;
			x /= d;
		}
		ans = min(ans, s / v);
	}
	cout << ans << endl;
}