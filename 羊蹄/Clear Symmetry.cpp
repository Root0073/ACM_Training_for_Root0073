#include <bits/stdc++.h>
using namespace std;
int main() {
	int x;
	cin >> x;
	//1 0 1
	//0 1 0 
	//1 0 1
	//5
//可以发现如果用偶数构造矩阵他的利用率非常低
	//0 1 0 1 0
	//1 0 1 0 1
	//0 1 0 1 0
	//1 0 1 0 1
	//0 1 0 1 0
	//8 - 13
	if(x == 3) {
		cout << 5 << endl;
		return 0;
	}
	vector<int> a = {1, 5, 13, 25, 41, 61, 85, 113};
	for(int i = 0; i < 8; i++) {
		if(x > a[i]) continue;
		else {
			cout << i * 2 + 1 << endl;
			return 0;
		}
	}

}
