#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solution() {
    int n, m, k, b, res = 0, cnt = 0;
    vector<vector<int> > a;
    cin >> n >> m >> k >> b;
    a.resize(n);
    for (int i = 0; i < n; ++i) a[i].resize(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) {
        int tot = 0, t = 0;
        for (int j = 0; j < m; ++j) tot += a[i][j], t += (a[i][j] <= 0);
        // cout<<"i = "<<i<<" tot = "<<tot<<" t = "<<t<<" tot+t-(m-t) = "<<tot+t-(m-t)<<'\n';
        if (tot >= k)
            ++res;
        else if (tot + t - (m - t) >= k)
            ++cnt;
    }
    cout << res + min(cnt, b) << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
2
5 3 2 1
-3 0 3
2 -2 -1
1 1 1
0 0 0
-1 -1 -1
3 2 -1 1
-1 -2
-3 -3
1 -3
*/