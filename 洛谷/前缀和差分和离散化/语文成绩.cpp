#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> delta(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        delta[i] += a[i];
        delta[i + 1] -= a[i];
    }
    while(p--) {
        int num, x, y;
        cin >> x >> y >> num;
        delta[x] += num;
        delta[y + 1] -= num;
    }
    long long ans = 1e9;
    for(int i = 1; i <= n; i++) {
        delta[i] += delta[i - 1];
        if(delta[i] < ans) ans = delta[i];
    }
    cout << ans << endl;
    return 0;
}//一切数据都以delta数组为准，因此原数组也可以插入到delta数组中