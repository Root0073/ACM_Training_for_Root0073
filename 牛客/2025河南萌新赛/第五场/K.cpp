#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int ans = inf;
    bool flag = false;
    auto dfs = [&](auto &dfs, int x, int y, int s) {
        if(x > tx || y > ty) return ;
        if(x == tx && y == ty) {
            ans = min(ans, s);
            flag = true;
            return ;
        }
        int add = max(x, y);
        dfs(dfs, x + add, y, s + 1);
        dfs(dfs, x, y + add, s + 1);
    };
    dfs(dfs, sx, sy, 0);
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
}