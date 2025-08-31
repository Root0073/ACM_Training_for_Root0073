#include <bits/stdc++.h>
using namespace std;
#define maxn 4010
int a[maxn][4];
int btop, ctop;
int f[maxn][maxn];
int main() {
    int n;
    cin >> n;
    vector<int> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> a[i][j];//0 1表示左上角 2 3表示右下角
            b.push_back(a[i][j]);
        }
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());//离散化操作
    map<int, int> mp;
    for(int i = 0; i < b.size(); i++) {
        mp[b[i]] = i;//标记在离散化数组中每一个数值的位置
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = mp[a[i][j]];//将原始坐标替换成离散化之后的索引值
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = a[k][0]; i < a[k][2]; i++) {
            f[i][a[k][3]]--, f[i][a[k][1]]++;//用差分数组标记矩阵覆盖情况
        }
    }
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            f[i][j] += f[i][j - 1];
        }
    }
    long long ans = 0;
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(f[i][j]) ans += (long long) (b[i + 1] - b[i]) * (b[j + 1] - b[j]);//将其转化为真实的值，我的ij原本都是虚拟值，是压缩成的一个小方格，真实值是下一个数据和上一个数据之间的差值
        }
    }
    cout << ans << endl;
    return 0;
}
//差分化的只是一个数据，在差分化数组里面并没有明确的含义，只是我暂时用差分化数组里面的下标代替了原来的下标，相当于把这一大串数据压缩成了一个下标，等我需要的时候再通过相邻的两个数相减得到真实值
//差分化就相当于新建一个数据集，便于我在面对大跨度数据的时候的处理，把一堆数据压缩成一个数据