#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    //AAABBB
    //AABABB
    //ABBBAA
    //AAABABBB
    //可以记住一个结论：对于多个单调递增的式子想最小化每个sigma(abs(x - y))只有当
    //x和y按照严格一一对应递增的关系才行
    //1 3 5 7
    //1 2 6 8
    //类似于这种
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