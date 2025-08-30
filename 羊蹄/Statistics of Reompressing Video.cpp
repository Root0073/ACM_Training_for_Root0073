#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
signed main() {
    int n, k;
    cin >> n >> k; 
    //通过观察我们可以知道一个数字的答案就是他入队的时间+他的b[i]值
    //因此我们只用维护他入队的时间就行
    vector<int> ans(n, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++) pq.push(0);
    int s, m;
    while(n--) {
        cin >> s >> m;
        int t = pq.top();
        pq.pop();
        t = max(t, s) + m;
        pq.push(t);
        cout << t << endl;
    }
}