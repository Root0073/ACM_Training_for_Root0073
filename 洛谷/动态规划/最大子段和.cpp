#include <bits/stdc++.h>
using namespace std;
long long f[1000000]; 
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	f[0] = a[0];
	long long ans = a[0]; 
	for(int i = 1; i < n; i++) {
		f[i] = max(f[i - 1], 0ll) + a[i];
		if(f[i] > ans) ans = f[i];
	}
	cout << ans << endl;
	return 0;
}//ע���ʼ�����⣬ans�ĳ�ʼֵӦ����a[0]��f[0]ҲӦ�ó�ʼ����a[0] 
