//离散化的经典题
#include <bits/stdc++.h>
using namespace std;
#define maxn 20010
int n, a[maxn], b[maxn],c[maxn * 2], f[maxn * 2], dtop, ctop, d[maxn * 2];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        d[++dtop] = a[i];
        d[++dtop] = b[i];
    }
    sort(d + 1, d + 1 + dtop);
    for(int i = 1; i <= dtop; i++) {
        if(d[i] != d[i - 1] || i == 1) c[++ctop] = d[i];//去重
    }
    for(int i = 1; i <= n; i++) {//这一步目的是为了找到所在的坐标
        int x = lower_bound(c + 1, c + ctop + 1, a[i]) - c;
        int y = lower_bound(c + 1, c + ctop + 1, b[i]) - c;
        for(int j = x; j < y; j++) {
            f[j] = 1;
        }
    }
    long long ans = 0;
    for(int i = 1; i < ctop; i++) {
        if(f[i] == 1) ans += c[i + 1] - c[i];                                   
    }
    cout << ans << endl;
}
//map是要存一下原来的点在离散化之后的数组中的位置
/*这个题也可以用map进行优化
在找到坐标找到这个阶段：mp[d[i]] = ctop
然后需要用到坐标的时候就不用二分去找了，直接x = mp[a[i]], y = mp[b[i]]*/