#include <bits/stdc++.h>
using namespace std;
int main() {
    //这道题的目的就是实现进制转换
    long long n, k;
    cin >> n >> k;
    int ans = 0;
    while(true) {
        if(n % k != 0) break;
        ans++;
        n /= k;
    }
    cout << ans << endl;
}