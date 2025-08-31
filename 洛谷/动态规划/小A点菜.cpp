#include <iostream>
#include <cstring>
using namespace std;
int f[10050], a[1005];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	};
	f[0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = m; j >= a[i]; j--) {
			f[j] += f[j - a[i]];
		}
	}
	cout << f[m] << endl;
	return 0;
}
//这其实是一个 01背包问题
//需要注意状态转移方程不再是取max了，而是 一直+= 
