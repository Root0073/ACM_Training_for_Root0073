#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int ans = inf;
    auto dfs = [&](auto &dfs, int x, int y, int s) {
        if(x > tx || y > ty) return ;
        if(x == tx && u == ty) {
            ans = min(ans, s);
            return ;
        }
        
    }
}