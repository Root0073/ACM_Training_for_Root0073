#include <bits/stdc++.h>
using namespace std;
vector<long long> coin(21);
const long long maxn = 1e9;
void solve() {
	long long n;
	cin >> n;
	long long ans = 0;
	int opt = 0;
	long long p = 1;
	while(n > 0) {
		ans += (n % 3) * (p * 3 + opt * p / 3); 
		p *= 3;
		n /= 3;
		opt++;
	}
	cout << ans << endl;
}
int main() {
	for(int i = 0; i <= 20; i++) {
		coin[i] = pow(3, i + 1) + i * pow(3, i - 1);
	}
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}