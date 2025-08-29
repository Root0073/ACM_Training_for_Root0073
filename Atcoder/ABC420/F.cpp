#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int st[maxn], l[maxn], r[maxn], top;
signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> h(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i * j <= k) cnt[i][j]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cnt[i][j] += 2 * cnt[i][j - 1];
            if(j > 1) cnt[i][j] -= cnt[i][j - 2];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '#') h[i][j] = 0;
            else h[i][j] = h[i - 1][j] + 1;
        }
    }
    auto cal = [&](int k, int x, int y) -> int {
        return cnt[k][x + y + 1] - cnt[k][x] - cnt[k][y];
    };
    int ans = 0;
    for(int id = 1; id <= n; id++) {
        for(int i = 1; i <= m; i++) {
            while(top && h[id][i] <= h[id][st[top]]) {
                int c = st[top--];
                r[c] = i - 1;
            }
            l[i] = st[top] + 1, st[++top] = i;
        }
        while(top) r[st[top--]] = m;
        for(int i = 1; i <= m; i++) ans += cal(h[id][i], i - l[i], r[i] - i);
    }
    cout << ans << endl;
}