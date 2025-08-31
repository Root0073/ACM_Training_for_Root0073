#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1, ans = 0x3f3f, amo = 0;
    int aa = 0, bb = 0;
    vector<int> cnt(k + 1);
    while(l <= r && r <= n + 1) {
        if(amo < k) {
            r++;
            cnt[a[r - 1]]++;
            if(cnt[a[r - 1]] == 1) amo++;
        }else {
            if(ans > r - l) {
                ans = r - l;
                aa = l;
                bb = r;
            }
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) amo--;
            l++;
        }
    }
    cout << aa << " " << bb - 1 << endl;
}