#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    vector<vector<char>> a(h + 1, vector<char>(w + 1));
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                sx = i, sy = j;
            }
            if(a[i][j] == 'G') {
                gx = i, gy = j;
            }
        }
    }
    queue<array<int, 4>> q;
    bool vis[500][500][2];
    memset(vis, false, sizeof(vis));
    q.push({sx, sy, 0, 0});
    vis[sx][sy][0] = true;
    while(!q.empty()) {
        auto [x, y, step, now] = q.front();
        q.pop();
        if(x == gx && y == gy) {
            cout << step << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx > h || ny > w || nx < 1 || ny < 1 || a[nx][ny] == '#') continue;

            if(a[nx][ny] == 'o' && now == 1) continue;
            if(a[nx][ny] == 'x' && now == 0) continue;
            int nn = now;
            if(a[nx][ny] == '?') nn ^= 1;
            if(!vis[nx][ny][nn]) {
                vis[nx][ny][nn] = true;
                q.push({nx, ny, step + 1, nn});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}