#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int> pqb;//大根堆
    priority_queue<int, vector<int>, greater<int>> pqs;//小根堆
    int ans = a[0];
    cout << ans << " ";
    for(int i = 1; i < n; i++) {
        if(a[i] > ans) pqs.push(a[i]);
        else pqb.push(a[i]);
        if(i % 2 == 1) {
            while(pqb.size() != pqs.size() + 1) {
                if(pqb.size() > pqs.size() + 1) {
                    pqs.push(ans);
                    ans = pqb.top();
                    pqb.pop();
                }else if(pqb.size() < pqs.size() + 1) {
                    pqb.push(ans);
                    ans = pqs.top();
                    pqs.pop();
                }
            }
                int next_val;
                if(pqb.size() > pqs.size()) {
                    next_val = pqb.top();
                } else {
                    next_val = pqs.top();
                }
                cout << (ans + next_val) / 2 << " ";
            }
        else {
            while(pqb.size() != pqs.size()) {
                if(pqb.size() > pqs.size()) {
                    pqs.push(ans);
                    ans = pqb.top();
                    pqb.pop();
                }else {
                    pqb.push(ans);
                    ans = pqs.top();
                    pqs.pop();
                }
            }
            cout << ans << " ";
        }
    }
}
