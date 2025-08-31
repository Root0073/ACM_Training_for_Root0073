#include <iostream>
using namespace std;
int f[10010][10010], a[1010];
#define mod 1000000007
int main() {
	int n, w;
	cin >> n >> w;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i]; j++) {
			f[i][j] = f[i - 1][j];
		}
		for(int j = a[i]; j <= w; j++) {
			f[i][j] = (f[i - 1][j - a[i]] + f[i - 1][j]) % mod;
		}
	}
	cout << f[n][w] << endl;
	return 0;
}
