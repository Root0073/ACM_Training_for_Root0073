//利用矩阵快速幂优化斐波那契数列推导过程
#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
struct matrix {
    long long a[3][3];
    matrix() {
        memset(a, 0, sizeof(a));
    }
    void init() {
        a[1][1] = a[1][2] = a[2][1] = 1;
        a[2][2] = 0;
    }
    matrix operator * (matrix b) {
        matrix res;
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= 2; j++) {
                for(int u = 1; u <= 2; u++) {
                    res.a[i][j] = (res.a[i][j] + a[i][u] * b.a[u][j] % mod) % mod;
                }
            }
        }
        return res;
    }
};
long long qpow(long long n) {
    matrix ans, base;
    ans.init();
    base.init();
    while(n > 0) {
        if(n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans.a[1][1];
}
int main() {
    long long n;
    cin >> n;
    cout << qpow(n) - 1 << endl;
}