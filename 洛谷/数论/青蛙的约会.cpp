#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    //这道题就是求在mod L的意义下(x + km) == (y + kn);
    //变形一下变成k(m - n) + zL = y - x;
    auto exgcd = [&](auto &exgcd, ll a, ll b, ll &x, ll &y) -> ll {
        if(b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = exgcd(exgcd, b, a % b, y, x);
        y -= a / b * x;
        return d;
    };
    ll x, y, n, m, l;
    cin >> x >> y >> m >> n >> l;
    int f = 1;
    if(m < n) {
        swap(n, m);
        f = -1;
    }
    ll z = 0, k = 0;
    int fd = exgcd(exgcd, m - n, l, k, z);
    if((y - x) % fd != 0) {
        cout << "Impossible" << endl;
        return 0;
    }else {
        k = k * f * (y - x) / fd;
        k = (k % (l / fd) + (l / fd)) % (l / fd);
        cout << k << endl;
        return 0;
    }
}