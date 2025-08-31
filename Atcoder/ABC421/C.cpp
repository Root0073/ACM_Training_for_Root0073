#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    //AAABBB
    //AABABB
    //ABBBAA
    //AAABABBB
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    int ans1 = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == 'A') {
            ans1 += abs(i - 2 * num);
            num++;
        }
        if(num == n) {
            break;
        }
    }
    num = 0;
    int ans2 = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == 'A') {
           ans2 += abs(i - (2 * num + 1));
           num++;
        }
        if(num == n) break;
    }
    cout << min(ans1, ans2) << endl;
    //1 4 5 7
    //1 2 3 4
}