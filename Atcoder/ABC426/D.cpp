#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	string s;
	cin >> n >> s;
	auto cal = [&](int num) -> long long {
		long long rec = 0;
		long long ans = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == num + '0') rec++;
			else {
				ans = max(ans, rec);
				rec = 0;
			}
		}
		ans = max(ans, rec);
		return ans;
	};
	long long num1 = 0, num0 = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '1') num1++;
		else num0++;
	}
	// cout << num1 << " " << num0 << endl;;
	// cout << cal(1) << " " << cal(0) << endl;
	long long ans1, ans0;
	ans1 = 2 * (num1 - cal(1)) + num0;
	ans0 = 2 * (num0 - cal(0)) + num1;
	cout << min(ans1, ans0) << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
